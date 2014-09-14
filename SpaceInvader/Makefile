CC	= gcc

# les nom de vos fichier doivent etre en minuscule si il ne sont pas bon renomer les mais ne toucher pas au Makefile
# les autre nom sont:
#				- Makefile qui garde la majuscule
#				- spritefunc.h en minuscule
#				- SampleStructureSprite.c garde sont nom car je sais pas ou c'est apeller 
SRC = main.c \
	  moon.c \
	  mars.c \
	  background.c \
	  ship.c \
	  bullet.c \
	  invader.c \
	  menu.c \
	  titre.c \
	  play.c \
	  quit.c \
	  utilitaire.c \
	  life.c\
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
