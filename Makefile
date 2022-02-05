# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:45:20 by jkosaka           #+#    #+#              #
#    Updated: 2022/02/05 16:47:20 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

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

.PHONY: all clean fclean re bonus empty
