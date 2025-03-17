#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_syntax() {
    FILE *makefile = fopen("Minimake_claered.mk", "r");
    if (makefile == NULL) {
        perror("Makefile not found");
        exit(1);
    }

    char line[1024];
    int line_number = 1;
    while (fgets(line, sizeof(line), makefile)) {
        // 检查目标行是否包含冒号
        if (strchr(line, ':') == NULL) {
            printf("Line%d:Missing colon in target definition\n", line_number);
        }
        // 检查命令是否以Tab开头
        if (strncmp(line, "\t", 1) != 0 && strchr(line, ':') == NULL) {
            printf("Line%d:Command found before rule\n", line_number);
        }
        line_number++;
    }

    fclose(makefile);
}
