#! /usr/bin/bash

CC=gcc
CFLAGS="-Wall -Werror -Wextra"

printf "${check}: "
cp "${check}"/main.c main_"${check}".c
COMP=$(${CC} ${CFLAGS} -o run_test_${check} *.c 2>&1)
if [ "${COMP}" != "" ]; then
    echo "${COMP}" >> test_history.log
    printf "${RED} Error during test compilation\n${DEFAULT}"
	return
fi
RC=$(./run_test_${check})
if [ $RC -eq 42 ]; then
    printf "${GREEN} OK ${DEFAULT}|"
else
    echo "ERROR: Expected: 42, test result: ${RC}" >> test_history.log
	printf "${RED} KO ${DEFAULT}|"
fi
if [ -e run_test_${check} ]; then
    rm run_test_${check}
fi
COMP=$(${CC} ${CFLAGS} -D BUFFER_SIZE=55 -o run_test_${check} *.c 2>&1)
if [ "${COMP}" != "" ]; then
    echo "${COMP}" >> test_history.log
    printf "${RED} Error during test compilation\n${DEFAULT}"
	return
fi
RC=$(./run_test_${check})
if [ $RC -eq 55 ]; then
    printf "${GREEN} OK ${DEFAULT}|"
else
    echo "ERROR: Expected: 55, test result: ${RC}" >> test_history.log
	printf "${RED} KO ${DEFAULT}|"
fi
printf "\n"
if [ -e run_test_${check} ]; then
    rm run_test_${check}
fi
if [ -e main_"${check}".c ]; then
    rm main_"${check}".c
fi