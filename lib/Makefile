##
## Makefile for  in /home/vienne_b/rendu/Piscine_C_bistromathique/lib
## 
## Made by axel vienne
## Login   <vienne_b@epitech.net>
## 
## Started on  Sun Nov  1 18:47:35 2015 axel vienne
## Last update Tue Dec 22 14:49:47 2015 puente_t
##

NAME	= libmy.a

SRC	= my/my_find_prime_sup.c \
	  my/my_atoi.c \
	  my/my_isneg.c \
	  my/my_is_prime.c \
	  my/my_power_rec.c \
	  my/my_putchar.c \
	  my/my_put_nbr.c \
	  my/my_put_unbr.c \
	  my/my_putstr.c \
	  my/my_revstr.c \
	  my/my_show_wordtab.c \
	  my/my_square_root.c \
	  my/my_strcapitalize.c \
	  my/my_strcat.c \
	  my/my_strcmp.c \
	  my/my_strcpy.c \
	  my/my_strdubl.c \
	  my/my_str_isalpha.c \
	  my/my_str_isnum.c \
	  my/my_str_islower.c \
	  my/my_str_isupper.c \
	  my/my_str_isprintable.c \
	  my/my_strlen.c \
	  my/my_strlowcase.c \
	  my/my_strncat.c \
	  my/my_strncmp.c \
	  my/my_strncpy.c \
	  my/my_strstr.c \
	  my/my_str_to_wordtab.c \
	  my/my_strupcase.c \
	  my/my_swap.c \
	  my/my_printf.c \
	  my/my_printf_prin1.c \
	  my/my_printf_prin2.c \
	  my/my_printf_prin3.c \
	  my/my_putnbr_printf.c

RM	= rm -f

CC	= gcc -I../include -Wall -Werror -ansi -pedantic

OBJ	= $(SRC:.c=.o)

COMPILE	= ar rc

RANLIB	= ranlib $(NAME)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(NAME) $(OBJ)
	$(RANLIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
