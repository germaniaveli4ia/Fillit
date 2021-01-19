NAME		:= fillit 

MAKE 		:= make
# directories
INC_DIR		:= ./includes
LIBFT		:= ./libft
LIBFT_INC	:= $(LIBFT)/includes
LIB_LNK 	:= -L $(LIBFT) -l ft

SRC			:=  validation.c \
				trial.c \
				main.c \
				coords.c	\
				list_support_funcs.c \
				grid_functions.c
OBJ			:= $(SRC:.c=.o)

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

%.o:%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC) -c $< -o $@

$(NAME): lib $(OBJ)
	@$(CC) $(OBJ) $(LIB_LNK) -I $(INC_DIR) -o $(NAME) $(CFLAGS) 

all: $(NAME)

clean:
	@$(MAKE) -C $(LIBFT) clean fclean --no-print-directory
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT) fclean --no-print-directory

re: fclean all

lib: 
	@$(MAKE) -C $(LIBFT) --no-print-directory

relib:
	@$(MAKE) -C $(LIBFT) re --no-print-directory
	@$(MAKE) re --no-print-directory
