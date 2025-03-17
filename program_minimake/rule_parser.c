#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule_parser.h"

MakefileRule rules[MAX_TARGETS];
int rule_count = 0;

void parse_rules() {
    FILE *makefile = fopen("Minimake_claered.mk", "r");
    if (makefile == NULL) {
        perror("Makefile not found");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), makefile)) {
        char *colon = strchr(line, ':');
        if (colon) {
            // 解析目标
            strncpy(rules[rule_count].target, line, colon - line);
            rules[rule_count].target[colon - line] = '\0';
            char *dependencies = colon + 1;
            // 解析依赖
            char *token = strtok(dependencies, " ");
            rules[rule_count].dependency_count = 0;
            while (token && rules[rule_count].dependency_count < MAX_DEPENDENCIES) {
                strncpy(rules[rule_count].dependencies[rules[rule_count].dependency_count], token, MAX_FILENAME_LENGTH);
                rules[rule_count].dependencies[rules[rule_count].dependency_count][MAX_FILENAME_LENGTH - 1] = '\0';
                rules[rule_count].dependency_count++;
                token = strtok(NULL, " ");
            }
            // 读取命令行
            fgets(line, sizeof(line), makefile);
            strncpy(rules[rule_count].command, line, MAX_COMMAND_LENGTH - 1);
            rules[rule_count].command[MAX_COMMAND_LENGTH - 1] = '\0';
            rule_count++;
        }
    }

    fclose(makefile);
}
