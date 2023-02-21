#! /usr/bin/bash

CC=gcc
CFLAGS="-Wall -Werror -Wextra"

printf "${check}: "
cp "${check}"/main.c main_"${check}".c

sizes=( '1' '4' '8' '22' '42' '55' '1000' '9999' '10000000' '100000000') 

for i in ${sizes[*]}
do
#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./run_test_${check}
    sed -i -e "s/read(\(.*\),\(.*\),.*);/read(\1,\2, $i);/g" get_next_line.c
    COMP=$(${CC} ${CFLAGS} -o run_test_${check} *.c 2>&1)
    if [ "${COMP}" != "" ]; then
        echo "${COMP}" >> test_history.log
        printf "${RED} Error during test compilation\n${DEFAULT}"
	    continue
    fi
    ./run_test_${check} ${check}/1.txt &>  ${check}/1.output
    DIFF=$(diff -U 3 ${check}/1.output ${check}/1.txt)
    if [ "$DIFF" != "" ]; then
        echo "${DIFF}" >> test_history.log
        printf "${RED} KO ${DEFAULT}|"
    else
        printf "${GREEN} OK ${DEFAULT}|"
    fi
done
printf "\n"
if [ -e ${check}/1.output ]; then
    rm ${check}/1.output
fi
if [ -e run_test_${check} ]; then
    rm run_test_${check}
fi
if [ -e main_"${check}".c ]; then
    rm main_"${check}".c
fi