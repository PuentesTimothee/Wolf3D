##
## Makefile for  in /home/puente_t/rendu/gfx_fdf1
## 
## Made by Timothée Puentes
## Login   <puente_t@epitech.net>
## 
## Started on  Thu Nov 12 16:07:04 2015 Timothée Puentes
## Last update Sun Dec 27 12:52:18 2015 puente_t
##

NAME		=	wolf3d

LIB		=	-L/home/${USER}/.froot/lib -llapin \
			-lsfml-audio -lsfml-graphics -lsfml-window \
			-lsfml-system -lstdc++ -ldl -lm -lmy -L../lib

CC		=	cc -W -Wall -Werror -ansi -pedantic \
			-I/home/${USER}/.froot/include/ -I../include 

SRC		=	main.c init.c load.c calc.c tekpixel.c move.c \
			tekline.c mini_map.c loader.c level_manag.c victory.c \
			write.c menu.c menu_useful.c texture.c sound.c help.c \
			antialias.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cd ../lib; make
		cd ../src
		$(CC) $(OBJ) $(LIB) -o $(NAME)

clean:
		cd ../lib; make clean
		cd ../src
		rm -f $(OBJ)

fclean:		clean
		cd ../lib; make fclean
		cd ../src
		rm -f $(NAME)

re:		fclean all

.PHONY:		re all clean fclean re
