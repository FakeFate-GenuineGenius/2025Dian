CC = gcc
CFLAGS = -Wall -Werror -Wpedantic

minimake: main.o argument_parser.o makefile_preprocessor.o syntax_checker.o rule_parser.o dependency_checker.o rebuild_checker.o command_executor.o
	$(CC) $(CFLAGS) -o minimake main.o argument_parser.o makefile_preprocessor.o syntax_checker.o rule_parser.o dependency_checker.o rebuild_checker.o command_executor.o

main.o: main.c argument_parser.h makefile_preprocessor.h syntax_checker.h rule_parser.h dependency_checker.h rebuild_checker.h command_executor.h
	$(CC) $(CFLAGS) -c main.c

argument_parser.o: argument_parser.c argument_parser.h
	$(CC) $(CFLAGS) -c argument_parser.c

makefile_preprocessor.o: makefile_preprocessor.c makefile_preprocessor.h
	$(CC) $(CFLAGS) -c makefile_preprocessor.c

syntax_checker.o: syntax_checker.c syntax_checker.h
	$(CC) $(CFLAGS) -c syntax_checker.c

rule_parser.o: rule_parser.c rule_parser.h
	$(CC) $(CFLAGS) -c rule_parser.c

dependency_checker.o: dependency_checker.c rule_parser.h
	$(CC) $(CFLAGS) -c dependency_checker.c

rebuild_checker.o: rebuild_checker.c rule_parser.h
	$(CC) $(CFLAGS) -c rebuild_checker.c

command_executor.o: command_executor.c rule_parser.h
	$(CC) $(CFLAGS) -c command_executor.c

clean:
	rm -f minimake *.o Minimake_claered.mk tmp_makefile
