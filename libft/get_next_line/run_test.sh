#! /usr/bin/bash

CC=gcc
CFLAGS="-Wall -Werror -Wextra"
DEPS="-lbsd libft.a"

printf "${func}: "
cp "${func}"/main.c main_"${func}".c

sizes=( '1' '4' '8' '22' '42' '55' '1000' '9999' '32767' '65536' '65537' '2147484') 

for i in ${sizes[*]}
do
#valgrind --leak-func=full --show-leak-kinds=all --track-origins=yes -s ./run_test_${func}
    COMP=$(${CC} ${CFLAGS} -D BUFFER_SIZE=${i} -o run_test_${func} main_"${func}".c ${DEPS} 2>&1)
    if [ "${COMP}" != "" ]; then
        echo "${COMP}" >> test_history.log
        printf "${RED} Error during test compilation\n${DEFAULT}"
	    continue
    fi
    ./run_test_${func} ${func}/1.txt >  ${func}/1.output
    DIFF=$(diff -U 3 ${func}/1.output ${func}/1.txt)
    if [ "$DIFF" != "" ]; then
        echo "${DIFF}" >> test_history.log
        printf "${RED} KO ${DEFAULT}|"
    else
        printf "${GREEN} OK ${DEFAULT}|"
    fi
done
printf "\n"
if [ -e ${func}/1.output ]; then
    rm ${func}/1.output
fi
if [ -e run_test_${func} ]; then
    rm run_test_${func}
fi
if [ -e main_"${func}".c ]; then
    rm main_"${func}".c
fi