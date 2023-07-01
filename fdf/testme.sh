#! /usr/bin/bash

# Change path to fdf
PATH_FDF=~/projects/fdf

# Define colors to use
DEFAULT="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
CYAN="\033[36m"

# https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
# Checks to test
checks=('check_minilibx')

# functions
fclean()
{
	rm -f fdf
}

# Removes folder wwith old tests
if [ -e fdf_src ]; then
    rm -rf fdf_src
fi

# Copy source folder
cp -r $PATH_FDF fdf_src

# Compile pipex
printf "${CYAN}Checking Norm and compilation:\n${DEFAULT}"
printf "Norminette check:"
#NORM=$(norminette fdf_src)
echo "" > norminette.log
NORM_ERR=$(grep Error norminette.log)
if [ "$NORM_ERR" != "" ]; then
    printf "${RED} KO ${DEFAULT}|\n"
else
    printf "${GREEN} OK ${DEFAULT}|\n"
fi
printf "fdf compilation:"
COMP=$(make -C fdf_src re 2>&1)
echo "$COMP" > compile.log
if [ ! -e  fdf_src/fdf ]; then
    printf "${RED} KO ${DEFAULT}|\n"
    exit
else
    printf "${GREEN} OK ${DEFAULT}|\n"
    fclean
    cp fdf_src/fdf .
fi

printf "" > test.log
# Make several test to evaluate fdf
printf "${CYAN}Testing mandatory part\n${DEFAULT}"
for check in ${checks[*]}
do
	source "${check}"/run_test.sh
done
fclean