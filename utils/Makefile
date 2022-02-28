# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:52:55 by jkosaka           #+#    #+#              #
#    Updated: 2022/02/28 17:44:38 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libutil.a

HEADERFILE := ../includes/utils.h

SRCS := error_handler.c get_next_line.c get_next_line_utils.c \
	slist.c fdf_split.c hex_atoi.c count_words.c math.c \

OBJS := $(SRCS:.c=.o)

LIBFT := ../libft/libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make -C ../libft
	cp $(LIBFT) $(NAME)
	ar rc $@ $^

all	: $(NAME)

%.o : %.c $(HEADERFILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ../libft
	$(RM) $(OBJS)

fclean : clean
	make fclean -C ../libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus