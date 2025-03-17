#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void preprocess_makefile() {
    FILE *makefile = fopen("./Makefile", "r");
    if (makefile == NULL) {
        perror("Makefile not found");
        exit(1);
    }

    FILE *tmp_file = fopen("tmp_makefile", "w");
    char line[1024];
    while (fgets(line, sizeof(line), makefile)) {
        // 去除注释
        char *comment = strchr(line, '#');
        if (comment) *comment = '\0';
        // 去除行尾空格
        while (strlen(line) > 0 && isspace(line[strlen(line) - 1])) line[strlen(line) - 1] = '\0';
        // 过滤空行
        if (strlen(line) > 0) {
            fprintf(tmp_file, "%s\n", line);
        }
    }

    fclose(makefile);
    fclose(tmp_file);
    // 重命名临时文件为清理后的文件
    rename("tmp_makefile", "Minimake_claered.mk");
}
