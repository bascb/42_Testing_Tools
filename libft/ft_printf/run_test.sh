CC=gcc
CFLAGS="-Wall -Werror -Wextra"
DEPS="-lbsd libft.a"

printf "${func}:"
cp "${func}"/main.c main_"${func}".c
cp "${func}"/main_ft.c main_"${func}"_ft.c
COMP=$(${CC} ${CFLAGS} -o run_test_${func} main_${func}.c ${DEPS} 2>&1)
COMP_FT=$(${CC} ${CFLAGS} -o run_test_${func}_ft main_${func}_ft.c ${DEPS} 2>&1)
if [ "${COMP}" != "" ] || [ "${COMP_FT}" != "" ]
	then
		echo "${COMP}" >> compile_history
		echo "${COMP_FT}" >> compile_history
		printf "${RED} Error during test compilation\n${DEFAULT}"
		return
fi
for i in {1..3}
do
	./run_test_${func} ${i} > "${func}"/test"${i}".expected
	./run_test_${func}_ft ${i} > "${func}"/test"${i}".output
	DIFF=$(diff -U 3 "${func}"/test"${i}".output "${func}"/test"${i}".expected)
	if [ "$DIFF" != "" ]
		then
			echo "${DIFF}" | cat -e >> compile_history
			printf "${RED} KO ${DEFAULT}|"
		else
			printf "${GREEN} OK ${DEFAULT}|"
	fi
	if [ -e "${func}"/test"${i}".expected ]
		then
			rm "${func}"/test"${i}".expected
	fi
	if [ -e "${func}"/test"${i}".output ]
		then
			rm "${func}"/test"${i}".output
	fi
done
if [ -e run_test_${func} ]
	then
		rm run_test_${func}
fi
if [ -e run_test_${func}_ft ]
	then
		rm run_test_${func}_ft
fi
if [ -e main_${func}.c ]
	then
		rm main_${func}.c
fi
if [ -e main_${func}_ft.c ]
	then
		rm main_${func}_ft.c
fi
printf "\n"