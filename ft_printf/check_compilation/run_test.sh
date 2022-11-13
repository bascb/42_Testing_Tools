#! /usr/bin/bash

CC=gcc
CFLAGS="-Wall -Werror -Wextra"
DEPS="libftprintf.a"

printf "${check}: "
for i in {1..7}
do
	cp "${check}"/main_${i}.c main_${i}.c
	cp "${check}"/main_${i}_ft.c main_${i}_ft.c
	COMP=$(${CC} ${CFLAGS} -o run_test_printf main_${i}.c ${DEPS} 2>&1)
	echo "${COMP}" | cat -e > "${check}"/test"${i}".expected
	COMP_FT=$(${CC} ${CFLAGS} -o run_test_ft_printf main_${i}_ft.c ${DEPS} 2>&1)
	echo "${COMP_FT}" | cat -e > "${check}"/test"${i}".output
	DIFF=$(diff -U 3 "${check}"/test"${i}".output "${check}"/test"${i}".expected)
	if [ "$COMP" != "" ] && [ "$COMP_FT" == "" ] || [ "$COMP" == "" ] && [ "$COMP_FT" != "" ]
		then
			echo "${DIFF}" | cat -e >> compile_history
			printf "${RED} KO ${DEFAULT}|"
		else
			printf "${GREEN} OK ${DEFAULT}|"
	fi
	if [ -e "${check}"/test"${i}".output ]
		then
			rm "${check}"/test"${i}".output
	fi
	if [ -e run_test_printf ]
		then
			rm run_test_printf
	fi
	if [ -e run_test_printf ]
		then
			rm run_test_printf_ft
	fi
	if [ -e main_${i}.c ]
		then
			rm main_${i}.c
	fi
	if [ -e main_${i}_ft.c ]
		then
			rm main_${i}_ft.c
	fi
done
printf "\n"
