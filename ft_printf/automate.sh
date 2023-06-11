#! /usr/bin/bash

# Change path to ft_printf
PATH_PRINTF=~/Desenvolvimento/42/projects/ft_printf

make -C "${PATH_PRINTF}" re
cp "${PATH_PRINTF}"/libftprintf.a libftprintf.a
cp "${PATH_PRINTF}"/ft_printf.h ft_printf.h
cp "${PATH_PRINTF}"/libft.h libft.h
make fclean
make all
./testing
