// dependency_checker.h
#ifndef DEPENDENCY_CHECKER_H
#define DEPENDENCY_CHECKER_H

#include "rule_parser.h"

int check_dependencies(const char *target);
void buildDependencyGraph();
void topologicalSort();

#endif
