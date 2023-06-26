#! /usr/bin/bash

# Change path to pipex
PATH_PIPEX=~/Desenvolvimento/42/projects/pipex

# Define colors to use
DEFAULT="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
CYAN="\033[36m"

# Checks to test
checks=('check_infile' 'check_ls_wc')

# functions
fclean()
{
	rm -f pipex
}

# Removes folder wwith old tests
if [ -e pipex_src ]; then
    rm -rf pipex_src
fi

# Copy source folder
cp -r $PATH_PIPEX pipex_src

# Compile pipex
printf "${CYAN}Checking Norm and compilation:\n${DEFAULT}"
printf "Norminette check:"
NORM=$(norminette pipex_src)
echo "$NORM" > norminette.log
NORM_ERR=$(grep Error norminette.log)
if [ "$NORM_ERR" != "" ]; then
    printf "${RED} KO ${DEFAULT}|\n"
else
    printf "${GREEN} OK ${DEFAULT}|\n"
fi
printf "pipex compilation:"
COMP=$(make -C pipex_src re 2>&1)
echo "$COMP" > compile.log
if [ ! -e  pipex_src/pipex ]; then
    printf "${RED} KO ${DEFAULT}|\n"
    exit
else
    printf "${GREEN} OK ${DEFAULT}|\n"
    fclean
    cp pipex_src/pipex .
fi

printf "" > test.log
# Make several test to evaluate pipex
printf "${CYAN}Testing mandatory part\n${DEFAULT}"
for check in ${checks[*]}
do
	source "${check}"/run_test.sh
done
fclean