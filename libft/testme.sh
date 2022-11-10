#! /usr/bin/bash

# Change path to libft
PATH_LIBFT=~/Desenvolvimento/42/projects/Libft

# Define colors to use
DEFAULT="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"

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
	else
		printf "${RED}Error on libft importing\n${DEFAULT}"
		printf "${YELLOW}Check compile_history for details\n${DEFAULT}"
		exit
fi
VAR_CALLOC=$(ar t libft.a ft_calloc.o)
printf "${VAR_CALLOC}\n"
