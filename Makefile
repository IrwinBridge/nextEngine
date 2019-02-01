NAME = doom-nukem
SRC = engine/*.c game/*.c

ifeq ($(shell uname -s), Linux)
HEADERS = -I/usr/include/SDL2/
LINKS = -lSDL2 -lSDL2_image
else
HEADERS = -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers \
		  -I ~/Library/Frameworks/SDL2_image.framework/Versions/A/Headers
LINKS = -F ~/Library/Frameworks/ -framework SDL2 -framework SDL2_image
endif
H_COMMON = -Igame/includes -Iengine/includes -Idependencies/libft
L_COMMON = -L./dependencies/libft -lft -lm -lpthread
GFLAGS = -Wall -Wextra -Werror -Ofast

$(NAME):
	make -C dependencies/libft
	gcc $(GFLAGS) $(SRC) $(HEADERS) $(LINKS) $(H_COMMON) $(L_COMMON) -o $(NAME)
	make clean -C dependencies/libft

all: $(NAME)

clean:
	/bin/rm -f dependencies/libft/*.o

fclean: clean
	/bin/rm -f dependencies/libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all
