#! /usr/bin/bash

# Define colors to use
DEFAULT="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"

# Change path to libft
PATH_LIBFT=~/Desenvolvimento/42/projects/Libft

printf "${YELLOW}Compiling libft library and executables for tests...\n${DEFAULT}"
make fclean > compile_history
make -C "${PATH_LIBFT}" fclean bonus >> compile_history
cp "${PATH_LIBFT}"/libft.a libft.a >> compile_history
cp "${PATH_LIBFT}"/libft.h libft.h >> compile_history
make all >> compile_history
if [ -e testing ]
	then
		printf "${GREEN}Compiled with success\n${DEFAULT}"
	else
		printf "${RED}Compilation failure\n${DEFAULT}"
		printf "${YELLOW}Check compile_history for details\n${DEFAULT}"
		exit
	fi
./testing
