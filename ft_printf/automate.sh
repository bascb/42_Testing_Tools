#! /usr/bin/bash

# Change path to ft_printf
PATH_PRINTF=~/projects/ft_printf

make -C "${PATH_PRINTF}" re
cp "${PATH_PRINTF}"/libftprintf.a libftprintf.a
cp "${PATH_PRINTF}"/libftprintf.h libftprintf.h
cp "${PATH_PRINTF}"/libft.h libft.h
make fclean
make all
./testing