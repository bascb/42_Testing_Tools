#! /usr/bin/bash

printf "${check}:"

ORIG=$(< infile ls -l)
echo "$ORIG" > no_infile.expected
TEST=$(./pipex infile "ls -l" "wc -l" no_infile.output)
echo "$TEST" > no_infile.output
DIFF=$(diff -U 3 no_infile.expected no_infile.output)
if [ "$DIFF" != "" ]
	then
		echo "${DIFF}" | cat -e >> test.log
		printf "${RED} KO ${DEFAULT}|"
	else
		printf "${GREEN} OK ${DEFAULT}|"
fi
printf "\n"