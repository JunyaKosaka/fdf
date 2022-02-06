# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:45:20 by jkosaka           #+#    #+#              #
#    Updated: 2022/02/06 18:28:29 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

FDF_DIR := ./src

$(NAME) : empty
	make -C $(FDF_DIR)

all : $(NAME)

bonus : empty
	make bonus -C $(FDF_DIR)

clean :
	make clean -C $(FDF_DIR)

fclean :
	make fclean -C $(FDF_DIR)

re : fclean all

empty :

test : fclean
	make -C $(FDF_DIR)
	./$(NAME) a.map

test2 : fclean
	make -C $(FDF_DIR)
	./$(NAME) julia.fdf

test3 : fclean
	make -C $(FDF_DIR)
	./$(NAME) ./test_maps/pyramide.fdf

fullclean :
	make fullclean -C $(FDF_DIR)

.PHONY: all clean fclean re bonus empty
