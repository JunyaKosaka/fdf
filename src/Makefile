# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:47:09 by jkosaka           #+#    #+#              #
#    Updated: 2022/02/09 14:17:58 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../fdf

SRCS := fdf.c get_file_map.c set_vectors.c free.c init_vectors.c \
	update_vecs.c draw_map.c events.c get_internal_vector.c \
	vector_utils.c rotate_vector.c draw_line.c \

OBJS := $(SRCS:%.c=%.o)

LIBUTIL := ../utils/libutil.a

MLX := ../minilibx-linux/libmlx.a

CC := cc

CFLAGS := -Wall -Wextra -Werror #-framework OpenGL -framework AppKit

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
	make -C ../minilibx-linux
	$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(OBJS) $(LIBUTIL) $(MLX)

all : $(NAME)

bonus : all
	make WITH_BONUS=1

# .c.o :
# 	$(CC) -c $< -o $@

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
#make clean -C ../libft
#make clean -C ../utils
#make clean -C ../minilibx-linux
	$(RM) $(OBJS) $(MAND_OBJS) $(BNS_OBJS)

fclean : clean
#fclean -C ../libft
#make fclean -C ../utils
	$(RM) $(NAME) $(LIBUTIL) $(MLX)

re : fclean all

fullclean : clean
	make fclean -C ../libft
	make fclean -C ../utils
	make clean -C ../minilibx-linux
	$(RM) $(NAME) $(LIBUTIL) $(MLX)

PHONY : fclean clean all re test retest