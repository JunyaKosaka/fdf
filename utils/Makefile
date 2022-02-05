# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:52:55 by jkosaka           #+#    #+#              #
#    Updated: 2022/02/05 17:10:20 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libutil.a

HEADERFILE := ../includes/utils.h

SRCS := error_handler.c

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