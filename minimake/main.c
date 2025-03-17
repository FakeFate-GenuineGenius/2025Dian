#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "argument_parser.h"
#include "makefile_preprocessor.h"
#include "syntax_checker.h"
#include "rule_parser.h"
#include "dependency_checker.h"
#include "rebuild_checker.h"
#include "command_executor.h"

int main(int argc, char *argv[]) {
    parse_arguments(argc, argv);
    preprocess_makefile();
    check_syntax();
    parse_rules();

    const char *target = get_target_argument();
    if (!check_dependencies(target)) {
        return 1;
    }
    if (need_rebuild(target)) {
        execute_command_for_target(target);
    }

    return 0;
}
