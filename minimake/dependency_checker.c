#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "rule_parser.h"

int check_dependencies(const char *target) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].target, target) == 0) {
            for (int j = 0; j < rules[i].dependency_count; j++) {
                struct stat st;
                if (stat(rules[i].dependencies[j], &st) != 0) {
                    printf("Invalid dependency '%s'\n", rules[i].dependencies[j]);
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}
