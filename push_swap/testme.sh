#! /usr/bin/bash

# Change path to pipex
PATH_PUSH=~/projects/push_swap

# Define colors to use
DEFAULT="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
CYAN="\033[36m"

# Checks to test
checks=('check_infile' 'check_ls_wc' 'check_wrong_command')

# functions
fclean()
{
	rm -f push_swap
	rm -f checker
}

# Removes folder wwith old tests
if [ -e push_src ]; then
    rm -rf push_src
fi

# Copy source folder
cp -r $PATH_PUSH push_src

# Compile pipex
printf "${CYAN}Checking Norm and compilation:\n${DEFAULT}"
printf "Norminette check:"
NORM=$(norminette push_src)
echo "$NORM" > norminette.log
NORM_ERR=$(grep Error norminette.log)
if [ "$NORM_ERR" != "" ]; then
    printf "${RED} KO ${DEFAULT}|\n"
else
    printf "${GREEN} OK ${DEFAULT}|\n"
fi
printf "push_swap compilation:"
COMP=$(make -C push_src re 2>&1)
echo "$COMP" > compile.log
if [ ! -e  push_src/push_swap ]; then
    printf "${RED} KO ${DEFAULT}|\n"
    exit
else
    printf "${GREEN} OK ${DEFAULT}|\n"
    fclean
    cp push_src/push_swap .
fi
printf "checker compilation:"
COMP=$(make -C push_src bonus 2>&1)
echo "$COMP" > compile.log
if [ ! -e  push_src/checker ]; then
    printf "${RED} KO ${DEFAULT}|\n"
    exit
else
    printf "${GREEN} OK ${DEFAULT}|\n"
    cp push_src/checker .
fi

#printf "" > test.log
# Make several test to evaluate pipex
#printf "${CYAN}Testing mandatory part\n${DEFAULT}"
#for check in ${checks[*]}
#do
#	source "${check}"/run_test.sh
#done
#fclean