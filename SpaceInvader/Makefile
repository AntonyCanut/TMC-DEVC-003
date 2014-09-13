CC	= gcc

SRC = Main.c \
	  Moon.c \
	  mars.c \
	  background.c \
	  Ship.c \
	  ShipShoot.c \
	  Invader.c \
	  Menu.c \
	  Titre.c \
	  Play.c \
	  Quit.c \
	  Utilitaire.c \
	  Life.c\
	  ~/Library/Frameworks/SDL2.framework/SDL2 \
	  ~/Library/Frameworks/SDL2_image.framework/SDL2_image \
	  ~/Library/Frameworks/SDL2_mixer.framework/SDL2_mixer


RM = rm -rf
NAME = SpaceInvader
OBJS = $(SRC:%.c=%.o)
# CFLAGS	= -W -Wall -Werror
# SDL2 = /usr/local/lib/libSDL2.a
# SDL2_image = /usr/local/lib/libSDL2_image.a
# SDL2_mixer = /usr/local/lib/libSDL2_mixer.a

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(SDL2) $(SDL2_image) $(SDL2_mixer) -o $(NAME)
			rm *.o

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
