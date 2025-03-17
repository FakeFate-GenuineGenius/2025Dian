#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "rule_parser.h"

int need_rebuild(const char *target) {
    struct stat target_stat;
    if (stat(target, &target_stat) != 0) {
        return 1;
    }

    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].target, target) == 0) {
            for (int j = 0; j < rules[i].dependency_count; j++) {
                struct stat dep_stat;
                if (stat(rules[i].dependencies[j], &dep_stat) == 0) {
                    if (dep_stat.st_mtime > target_stat.st_mtime) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }
    return 0;
}
