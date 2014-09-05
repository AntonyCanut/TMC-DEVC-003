CC	= gcc

SRC = Main.c\
	  Moon.c\
	  mars.c\
	  background.c\
	  SpaceShip.c\
	  ~/Library/Frameworks/SDL2.framework/SDL2\
	  ~/Library/Frameworks/SDL2_image.framework/SDL2_image


 NAME = SpaceInvader
 OBJ = $(SRC:%.c=%.o)
 all:		$(NAME)

 $(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
