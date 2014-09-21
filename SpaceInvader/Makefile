CC	= gcc

# les nom de vos fichier doivent etre en minuscule si il ne sont pas bon renomer les mais ne toucher pas au Makefile
# les autre nom sont:
#				- Makefile qui garde la majuscule
#				- spritefunc.h en minuscule
#				- SampleStructureSprite.c est un exemple de code de Sprite, il ne fait qu'expliquer le role de chaque partie. Si compris alors peut être retiré
SRC = main.c \
	  game.c \
	  Layout/moon.c \
	  Layout/mars.c \
	  Layout/background.c \
	  Layout/layout.c \
	  Players/ship.c \
	  Players/bullet.c \
	  Players/invader.c \
	  Menu/menu.c \
	  Menu/titre.c \
	  Menu/play.c \
	  Menu/quit.c \
	  Menu/pause.c \
	  utilitaire.c \
	  Function/listFunctions.c \
	  Players/life.c\
	  Players/boss.c\

RM = rm -rf
NAME = SpaceInvader
OBJS = $(SRC:%.c=%.o)
<<<<<<< HEAD
CFLAGS	= -I/usr/local/include/SDL2 -D_THREAD_SAFE -L/usr/local/lib -lSDL2
LDFLAGS = -lSDLmain -lSDL -Wl,-framework,Cocoa
SDL2_Path =	~/Library/Frameworks/SDL2.framework/SDL2 \
			~/Library/Frameworks/SDL2_image.framework/SDL2_image \
			~/Library/Frameworks/SDL2_mixer.framework/SDL2_mixer
SDL2 = /usr/local/lib/libSDL2.a
SDL2_image = /usr/local/lib/libSDL2_image.a
SDL2_mixer = /usr/local/lib/libSDL2_mixer.a
=======
# CFLAGS	= -W -Wall -Werror
# SDL2 = /usr/local/lib/libSDL2.a
# SDL2_image = /usr/local/lib/libSDL2_image.a
# SDL2_mixer = /usr/local/lib/libSDL2_mixer.a
>>>>>>> FETCH_HEAD

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(SDL2_Path) $(SDL2) $(SDL2_image) $(SDL2_mixer) -o $(NAME)
			rm $(OBJS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
