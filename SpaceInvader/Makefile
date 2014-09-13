CC	= gcc

SRC = Main.c \
	  Moon.c \
	  Mars.c \
	  background.c \
	  Ship.c \
	  ShipShoot.c \
	  Invader.c \
	  Menu.c \
	  Titre.c \
	  Utilitaire.c

RM = rm -rf
NAME = SpaceInvader
OBJS = $(SRC:%.c=%.o)
# CFLAGS	= -W -Wall -Werror
SDL2 = ~/Library/Frameworks/SDL2.framework/SDL2
SDL2_image = ~/Library/Frameworks/SDL2_image.framework/SDL2_image
SDL2_mixer = ~/Library/Frameworks/SDL2_mixer.framework/SDL2_mixer

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(SRC) $(SDL2) $(SDL2_image) $(SDL2_mixer) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
