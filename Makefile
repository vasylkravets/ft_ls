# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkravets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 11:58:28 by vkravets          #+#    #+#              #
#    Updated: 2018/02/13 11:58:30 by vkravets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_print.c ft_sort_data.c read_dir.c ft_flag_l.c list_func.c \
	error_func.c ft_add_list.c print_all.c

F =  -Wall -Wextra -Werror

O = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
		@gcc -c $? $(FILES) $(F)

BLUE		=	\033[0;94m
YELLOW		=	\033[0;33m
LIGHT 		= 	\033[0;5m
COLOR_OFF	= 	\033[0m

$(NAME): $(O)
	@echo "$(YELLOW)compiling..."
	@make -C libft
	@make -C ft_printf
	@gcc $(F) $(O) libft/libft.a ft_printf/libftprintf.a -o $(NAME)
	@echo "$(LIGHT)ft_ls is ready"

clean:
	@echo "$(BLUE)deleting objects files...$(COLOR_OFF)"
	@make clean -C ./libft/ 
	@make clean -C ./ft_printf/
	@rm -f $(O)
cleanlib:
	@echo "$(BLUE)deleting objects files in libft/ft_printf...$(COLOR_OFF)"
	@make clean -C ./libft/ 
	@make clean -C ./ft_printf/
fcleanlib:
	@make fclean -C ./libft/
	@make fclean -C ./ft_printf/
fclean: clean fcleanlib
	@echo "$(BLUE)deleting exe_file and libraries...$(COLOR_OFF)"
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean fcleanlib cleanlib
