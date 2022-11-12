#! /usr/bin/bash

CC=gcc
CFLAGS="-Wall -Werror -Wextra"
DEPS="-lbsd libft.a"

printf "${func}:"
cp "${func}"/main.c main_"${func}".c
COMP_RET=$(${CC} ${CFLAGS} -o run_test_${func} main_${func}.c ${DEPS} 2>&1)
if [ "${COMP_RET}" != "" ]
	then
		echo "${COMP_RET}" >> compile_history
		printf "${RED} Error during test compilation\n${DEFAULT}"
		return
fi
./run_test_${func}
for i in {1..7}
do
	DIFF=$(diff -U 3 "${func}"/test"${i}".output "${func}"/test"${i}".expected)
	if [ "$DIFF" != "" ]
		then
			echo "${DIFF}" | cat -e >> compile_history
			printf "${RED} KO ${DEFAULT}|"
		else
			printf "${GREEN} OK ${DEFAULT}|"
	fi
	if [ -e "${func}"/test"${i}".output ]
		then
			rm "${func}"/test"${i}".output
	fi
done
printf "\n"