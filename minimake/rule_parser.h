#ifndef RULE_PARSER_H
#define RULE_PARSER_H

#define MAX_TARGETS 100
#define MAX_DEPENDENCIES 10
#define MAX_COMMAND_LENGTH 1024
#define MAX_FILENAME_LENGTH 32

typedef struct {
    char target[MAX_FILENAME_LENGTH];
    char dependencies[MAX_DEPENDENCIES][MAX_FILENAME_LENGTH];
    int dependency_count;
    char command[MAX_COMMAND_LENGTH];
} MakefileRule;

extern MakefileRule rules[MAX_TARGETS];
extern int rule_count;

void parse_rules();

#endif
