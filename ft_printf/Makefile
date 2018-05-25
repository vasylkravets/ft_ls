# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkravets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:12:04 by vkravets          #+#    #+#              #
#    Updated: 2017/11/09 17:12:05 by vkravets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_isdigit.c ft_memset.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsub.c \
 main_func.c  check_flag.c check_spec.c ft_check_cpec_su.c ft_check_cpec_chu.c ft_subfunc_for.c print_spec_su.c ft_spec_s.c \
ft_check_cpec_chu.c ft_for_spec_c.c ft_for_spec_d.c  ft_format_acord_flags.c ft_for_spec_i.c ft_for_spec_u.c \
ft_for_spec_x.c ft_for_spec_xl.c ft_for_spec_o.c ft_for_spec_p.c ft_putstr.c ft_memdel.c ft_atoi.c ft_memdel.c ft_check_interest.c


F = -Wall -Wextra -Werror
O = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(O)
	@ar rcs $@ $(O)

%.o: %.c
	@gcc $(F) -c $< -o $@
clean:
	@/bin/rm -f $(O)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re