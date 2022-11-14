#! /usr/bin/bash

CC=gcc
CFLAGS="-Wall -Werror -Wextra"
DEPS="libftprintf.a"

printf "${check}:"
cp "${check}"/main.c main_"${check}".c
COMP=$(${CC} ${CFLAGS} -o run_test_${check} main_${check}.c ${DEPS} 2>&1)
if [ "${COMP}" != "" ]
	then
		echo "${COMP}" >> compile_history
		printf "${RED} Error during test compilation\n${DEFAULT}"
		return
fi
for i in {1..3}
do
	./run_test_${check} ${i}
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
if [ -e main_${check}.c ]
	then
		rm main_${check}.c
fi
printf "\n"
