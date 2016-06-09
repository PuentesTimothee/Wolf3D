##
## Makefile for  in /home/puente_t/rendu/gfx_fdf1
## 
## Made by Timothée Puentes
## Login   <puente_t@epitech.net>
## 
## Started on  Thu Nov 12 16:07:04 2015 Timothée Puentes
## Last update Tue Dec 15 13:33:55 2015 puente_t
##

NAME		=	wolf3d

all:		$(NAME)

$(NAME):
		cd src; make
		cd ..
		cp src/$(NAME) .

clean:
		cd src; make clean
		cd ..

fclean:		clean
		cd src; make fclean
		cd ..
		rm -f $(NAME)

re:		fclean all

