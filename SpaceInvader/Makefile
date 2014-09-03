##
## Makefile for  in /Users/valentin/Desktop/ProjetC/my_cat
## 
## Made by Valentin Carriere
## Login   <carrie_v@etna-alternance.net>
## 
## Started on  Tue Feb 25 22:46:11 2014 Valentin Carriere
## Last update Wed Feb 26 16:55:52 2014 Valentin Carriere
##

CC	= gcc

SRC = Main.c /Library/Frameworks/SDL2.framework/SDL2 /Library/Frameworks/SDL2_image.framework/SDL2_image

NAME = SpaceInvader

OBJ = $(SRC:%.c=%.o)



all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all