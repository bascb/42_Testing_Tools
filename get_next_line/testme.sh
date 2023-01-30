#! /usr/bin/bash

# Change path to source code
SOURCE_PATH=~/Desenvolvimento/42/projects/get_next_line

# Define colors to use
DEFAULT="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
CYAN="\033[36m"

# Checks to test
checks=('check_compilation' 'some_text_files' 'change_buffer_size' 'stdin')
bonus=('several_files')

# functions
fclean()
{
	rm -f *.o
    rm -f *.c
    rm -f *.h
}

echo "Results of get_next_line function tests" > test_history.log
fclean
RC=$(find ${SOURCE_PATH} ! -iregex ".*\_bonus.*" -iregex ".*\.c" -exec cp {} . \;)
if [ "$RC" != "" ]; then
    printf "${RED} Unable to copy source files\n${DEFAULT}"
    echo "ERROR: $RC" >> test_history.log
    exit
fi
RC=$(find ${SOURCE_PATH} ! -iregex ".*\_bonus.*" -iregex ".*\.h" -exec cp {} . \;)
if [ "$RC" != "" ]; then
    printf "${RED} Unable to copy source files\n${DEFAULT}"
    echo "ERROR: $RC" >> test_history.log
    exit
fi
printf "${CYAN}Testing get_next_line\n${DEFAULT}"
for check in ${checks[*]}
do
	source "${check}"/run_test.sh
done
fclean

RC=$(cp ${SOURCE_PATH}/*bonus.c .)
if [ "$RC" != "" ]; then
    printf "${RED} Unable to copy source files\n${DEFAULT}"
    echo "ERROR: $RC" >> test_history.log
    exit
fi
RC=$(cp ${SOURCE_PATH}/*bonus.h .)
if [ "$RC" != "" ]; then
    printf "${RED} Unable to copy source files\n${DEFAULT}"
    echo "ERROR: $RC" >> test_history.log
    exit
fi

printf "${CYAN}Testing bonus part\n${DEFAULT}"
for check in ${bonus[*]}
do
	source "${check}"/run_test.sh
done
fclean