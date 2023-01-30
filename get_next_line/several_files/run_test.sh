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
for i in {1..4}
do
    touch ${check}/${i}.output
done 
./run_test_${check}
for i in {1..4}
do
#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./run_test_${check}
    DIFF=$(diff -U 3 ${check}/${i}.output ${check}/${i}.txt)
    if [ "$DIFF" != "" ]; then
        echo "${DIFF}" >> test_history.log
        printf "${RED} KO ${DEFAULT}|"
    else
        printf "${GREEN} OK ${DEFAULT}|"
    fi
    if [ -e ${check}/${i}.output ]; then
        rm ${check}/${i}.output
    fi
done
printf "\n"
if [ -e run_test_${check} ]; then
    rm run_test_${check}
fi
if [ -e main_"${check}".c ]; then
    rm main_"${check}".c
fi