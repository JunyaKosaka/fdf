# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:47:09 by jkosaka           #+#    #+#              #
#    Updated: 2022/02/05 18:58:40 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../fdf

SRCS := fdf.c get_file_map.c

OBJS := $(SRCS:%.c=%.o)

LIBUTIL := ../utils/libutil.a

MLX := ../libmlx.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror -framework OpenGL -framework AppKit

MAND := main.c

MAND_OBJS := $(MAND:%.c=%.o)

BONUS := 

BNS_OBJS := $(BONUS:%.c=%.o)

ifdef WITH_BONUS
OBJS += $(BNS_OBJS)
else
OBJS += $(MAND_OBJS)
endif

$(NAME) : $(OBJS)
	make -C ../utils
	make -C ../minilibx_macos
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBUTIL) $(MLX)

all : $(NAME)

bonus : all
	make WITH_BONUS=1

.c.o :
	$(CC) -c $< -o $@

clean :
#make clean -C ../libft
	make clean -C ../utils
#make clean -C ../minilibx_macos
	$(RM) $(OBJS) $(MAND_OBJS) $(BNS_OBJS)

fclean : clean
#fclean -C ../libft
	make fclean -C ../utils
	$(RM) $(NAME) $(LIBUTIL) $(MLX)

re : fclean all

fullclean :
	make fclean -C ../libft
	make fclean -C ../utils
	make clean -C ../minilibx_macos
	$(RM) $(NAME) $(LIBUTIL) $(MLX)

PHONY : fclean clean all re test retest