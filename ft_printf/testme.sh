#! /usr/bin/bash

# Change path to libftprintf
PATH_LIBFTPRINTF=~/Desenvolvimento/42/projects/ft_printf

# Define colors to use
DEFAULT="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
CYAN="\033[36m"

# Checks to test
checks=('check_compilation' 'check_output_order' 'check_percentage_escape' 'check_strings'\
		'check_chars' 'check_integers' 'check_unsigned' 'check_hexa' 'check_pointers'\
		'check_+_flag' 'check_space_flag' 'check_#_flag' 'check_width_flag'\ 
		'check_minus_flag' 'check_0_flag' 'check_precision_flag')

# functions
fclean()
{
	rm -f *.o
	rm -f testing
	rm -f libft.a
	rm -f libft.h
	rm -f libftprintf.a
	rm -f libftprintf.h
}


printf "${YELLOW}Compiling and importing libftprintf library...\n${DEFAULT}"
fclean > compile_history
make -C "${PATH_LIBFTPRINTF}" re >> compile_history
cp "${PATH_LIBFTPRINTF}"/libft.h libft.h >> compile_history
cp "${PATH_LIBFTPRINTF}"/libftprintf.a libftprintf.a >> compile_history
cp "${PATH_LIBFTPRINTF}"/libftprintf.h libftprintf.h >> compile_history
if [ -e libftprintf.a ]
	then
		printf "${GREEN}libftprintf imported with success\n${DEFAULT}"
		make -C "${PATH_LIBFTPRINTF}" fclean >> compile_history
	else
		printf "${RED}Error on libftprintf importing\n${DEFAULT}"
		printf "${YELLOW}Check compile_history for details\n${DEFAULT}"
		exit
fi
printf "${CYAN}Testing ft_printf\n${DEFAULT}"
for check in ${checks[*]}
do
	source "${check}"/run_test.sh
done
fclean
