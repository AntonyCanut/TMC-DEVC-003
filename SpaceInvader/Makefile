CC	= gcc

SRC = Main.c\
	  Moon.c\
	  Mars.c\
	  Background.c\
	  Ship.c\
	  ShipShoot.c\
	  Invader.c\
<<<<<<< HEAD
	  Menu.c\
	  Titre.c\
=======
	  Utilitaire.c
>>>>>>> FETCH_HEAD

RM = rm -rf
NAME = SpaceInvader
OBJS = $(SRC:%.c=%.o)
# CFLAGS	= -W -Wall -Werror
SDL2 = ~/Library/Frameworks/SDL2.framework/SDL2
SDL2_image = ~/Library/Frameworks/SDL2_image.framework/SDL2_image
SDL2_mixer = ~/Library/Frameworks/SDL2_mixer.framework/SDL2_mixer

$(NAME):	
			$(CC) $(SRC) $(SDL2) $(SDL2_image) $(SDL2_mixer) -o $(NAME)
			#rm *.o
			# ./$(NAME)

clean:
			rm *.o
