#! /usr/bin/bash

printf "${check}:"

for i in {1..3}
do
    < ${check}/${i}.in ls -l | wc -l > ${check}/${i}.expected
    MEM_CHECK=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./pipex ${check}/${i}.in "ls -l" "wc -l" ${check}/${i}.output 2>&1)
    MEM_CLEAN=$(echo "$MEM_CHECK" | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
    DIFF=$(diff -U 3 ${check}/${i}.output ${check}/${i}.expected)
    if [ "$DIFF" != "" ] || [ "$MEM_CLEAN" == "" ]; then
        echo "${DIFF}" >> test.log
        if [ "$MEM_CLEAN" == "" ]; then
            echo "${MEM_CHECK}" >> test.log
        fi
        printf "${RED} KO ${DEFAULT}|"
    else
        printf "${GREEN} OK ${DEFAULT}|"
    fi
    if [ -e ${check}/${i}.output ]; then
        rm ${check}/${i}.output
    fi
    if [ -e ${check}/${i}.expected ]; then
        rm ${check}/${i}.expected
    fi
done
printf "\n"