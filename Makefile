# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/27 18:18:00 by etermeau          #+#    #+#              #
#    Updated: 2015/02/21 18:37:43 by etermeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB = libft/

HEADER = includes/

DIRSRC = srcs/

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  ft_ls.c \
	  ft_sort.c \
	  ft_print_ls.c \
	  ft_erreur.c \
	  ft_option.c \
	  ft_list.c \
	  ft_reverse.c \
	  ft_prt_info_str.c \
	  ft_prt_info_nbr.c \
	  ft_prt_right.c \
	  ft_opt_t.c \
	  ft_get_info.c \
	  ft_recursive.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft

%.o: $(DIRSRC)%.c
	@gcc $(FLAGS) -o $@ -c $< -I$(LIB)$(HEADER) -I$(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIB)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIB)

re: fclean all
