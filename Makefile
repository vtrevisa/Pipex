#--STANDART--#
NAME	= pipex
ODIR	= ./objects
CFLAGS	= -Wall -Wextra -Werror -g3

#--LIBFT--#
LIBFT	= $(addprefix $(LPATH)/, libft.a)
LPATH	= ./Libft/

#--MANDATORY--#
SRC = pipex.c utils.c error.c process.c utils2.c
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LPATH)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re