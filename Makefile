NAME 		= cub3D
CC 			= cc
RM			= rm -f

CFLAGS 		+= -g -Wall -Wextra -Werror
FT			= libft
LIBFT		= $(FT)/libft.a
DEBUG		= 0

SRC		=	$(wildcard src/*.c)
OBJ		= $(SRC:.c=.o)

all:
	@printf "\033[1;36m\nStarting Cub3d compilation\n\e[0m"
	@make -s redirect

redirect: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline
	@printf "\033[1;92m >>> Cub3d compiled                                                     \n\n\033[0m"
	
$(LIBFT): $(FT)
	@printf "\033[1;35m\n\t| Starting libft compilation\n\e[0m"
	@make -s -C $(FT)

%.o: %.c
	@printf "\033[0;33mCompilation de %-33.33s\r\e[0m" $@
	@if [ $(DEBUG) -eq 1 ]; then $(CC) $(CFLAGS) -c $< -o $@ -D DEBUG=1; else $(CC) $(CFLAGS) -c $< -o $@; fi

clean:
	@$(RM) $(OBJ)
	@if [ -d "$(FT)" ]; then make -s fclean -C $(FT); fi
	@$(RM) $(LIBFT)
	@printf "\033[1;31m- Object files deleted\n\033[0m"

fclean: clean	
	@$(RM) $(NAME)
	@printf "\033[1;31m- Executable file deleted\n\033[0m"

re: fclean all

test:
	@make -s re
	@make -s clean
	@clear
	@echo "\033[1;92mDONE !"

norminette:
	@clear
	@sh ~/better_norminette.sh

debug: fclean
	@make -s DEBUG=1 all
	@make clean
	@clear

.PHONY: all redirect clean fclean re ft test norminette debug
