// rebuild_checker.h
#ifndef REBUILD_CHECKER_H
#define REBUILD_CHECKER_H

#include "rule_parser.h"

// 判断目标是否需要重新构建
int need_rebuild(const char *target);

#endif
