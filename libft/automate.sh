#! /usr/bin/bash

# Change path to libft
PATH_LIBFT=~/Desenvolvimento/42/projects/Libft

cp "${PATH_LIBFT}"/libft.a libft.a
cp "${PATH_LIBFT}"/libft.h libft.h
make fclean
make all
