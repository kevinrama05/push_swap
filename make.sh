rm libft.a
cd libft
make
make clean
mv libft.a ..
cd ..
cc -g -Wall -Wextra -Werror main.c libft.a -o push_swap

