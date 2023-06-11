#! /usr/bin/bash

# Change path to libft
PATH_LIBFT=~/Desenvolvimento/42/projects/libft

# Define colors to use
DEFAULT="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
CYAN="\033[36m"

# Other sources
source functions.sh

# functions
fclean()
{
	rm -f *.o
	rm -f testing
	rm -f libft.a
	rm -f libft.h
}


printf "${YELLOW}Compiling and importing libft library...\n${DEFAULT}"
fclean > compile_history
make -C "${PATH_LIBFT}" fclean bonus >> compile_history
cp "${PATH_LIBFT}"/libft.a libft.a >> compile_history
cp "${PATH_LIBFT}"/libft.h libft.h >> compile_history
if [ -e libft.a ]
	then
		printf "${GREEN}libft imported with success\n${DEFAULT}"
		make -C "${PATH_LIBFT}" fclean >> compile_history
	else
		printf "${RED}Error on libft importing\n${DEFAULT}"
		printf "${YELLOW}Check compile_history for details\n${DEFAULT}"
		exit
fi
FUNC_OBJS=$(ar t libft.a)
printf "${CYAN}Testing Part 2 functions\n${DEFAULT}"
for func in ${Part2_func[*]}
do
	for obj in ${FUNC_OBJS[*]}
	do
		if [ "${func}.o" == "${obj}" ]
			then
				source "${func}"/run_test.sh
				if [ -e run_test_${func} ]
					then
						rm run_test_${func}
				fi
				if [ -e main_${func}.c ]
					then
						rm main_${func}.c
				fi
		fi
	done
done
printf "${CYAN}Testing Extra functions\n${DEFAULT}"
for func in ${Extra_func[*]}
do
	for obj in ${FUNC_OBJS[*]}
	do
		if [ "${func}.o" == "${obj}" ]
			then
				source "${func}"/run_test.sh
				if [ -e run_test_${func} ]
					then
						rm run_test_${func}
				fi
				if [ -e main_${func}.c ]
					then
						rm main_${func}.c
				fi
		fi
	done
done
fclean
