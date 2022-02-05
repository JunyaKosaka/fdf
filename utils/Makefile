# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:52:55 by jkosaka           #+#    #+#              #
#    Updated: 2022/02/06 01:22:09 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libutil.a

HEADERFILE := ../includes/utils.h

SRCS := error_handler.c get_next_line.c get_next_line_utils.c \
	slist.c fdf_split.c hex_atoi.c \

OBJS := $(SRCS:%.c=%.o)

FLAGS := -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make $(FLAGS) -C ../libft
	cp ../libft/libft.a $(NAME)
	ar rc $@ $^

all	: $(NAME)

%.o : %.c $(HEADERFILE)
	gcc $(FLAGS) -c $< -o $@

clean :
#make clean -C ../libft
	$(RM) -f $(OBJS)

fclean : clean
#make fclean -C ../libft
	$(RM) -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus