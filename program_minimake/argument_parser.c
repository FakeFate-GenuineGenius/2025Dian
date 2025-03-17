#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *target_arg = NULL;

void parse_arguments(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        printf("Usage: minimake [target]\n");
        exit(0);
    } else if (argc == 2) {
        target_arg = argv[1];
    } else {
        printf("Invalid arguments\n");
        exit(1);
    }
}

const char *get_target_argument() {
    return target_arg;
}
