#! /usr/bin/bash

CC=gcc
CFLAGS="-Wall -Werror -Wextra"
DEPS="libftprintf.a"

conversions=('i/d' 'u' 'x/X' 's')

printf "${check}:"
cp "${check}"/main.c main_"${check}".c
cp "${check}"/main_ft.c main_"${check}"_ft.c
COMP=$(${CC} ${CFLAGS} -o run_test_${check} main_${check}.c ${DEPS} 2>&1)
COMP_FT=$(${CC} ${CFLAGS} -o run_test_${check}_ft main_${check}_ft.c ${DEPS} 2>&1)
if [ "${COMP}" != "" ] || [ "${COMP_FT}" != "" ]
	then
		echo "${COMP}" >> compile_history
		echo "${COMP_FT}" >> compile_history
		printf "${RED} Error during test compilation\n${DEFAULT}"
		return
fi
for i in {1..10}
do
	./run_test_${check} ${i} > "${check}"/test"${i}".expected
	./run_test_${check}_ft ${i} > "${check}"/test"${i}".output
	DIFF=$(diff -U 3 "${check}"/test"${i}".output "${check}"/test"${i}".expected)
	if [ "$DIFF" != "" ]
		then
			echo "${DIFF}" | cat -e >> compile_history
			printf "${RED} KO ${DEFAULT}|"
		else
			printf "${GREEN} OK ${DEFAULT}|"
	fi
	if [ -e "${check}"/test"${i}".expected ]
		then
			rm "${check}"/test"${i}".expected
	fi
	if [ -e "${check}"/test"${i}".output ]
		then
			rm "${check}"/test"${i}".output
	fi
done
if [ -e run_test_${check} ]
	then
		rm run_test_${check}
fi
if [ -e run_test_${check}_ft ]
	then
		rm run_test_${check}_ft
fi
if [ -e main_${check}.c ]
	then
		rm main_${check}.c
fi
if [ -e main_${check}_ft.c ]
	then
		rm main_${check}_ft.c
fi
printf "\n"
