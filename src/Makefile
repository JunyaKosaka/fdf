# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:47:09 by jkosaka           #+#    #+#              #
#    Updated: 2022/02/28 17:45:42 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../fdf

HEADERFILE := ../includes/fdf.h

SRCS := fdf.c get_file_map.c set_vectors.c free.c init_vectors.c \
	update_vecs.c render_map.c events.c get_internal_vector.c \
	vector_utils.c rotate_vector.c render_line.c color.c \

OBJS := $(SRCS:.c=.o)

LIBUTIL := ../utils/libutil.a

MLX := ../minilibx-linux/libmlx.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

MAND := main.c

MAND_OBJS := $(MAND:.c=.o)

BONUS := main_bonus.c

BNS_OBJS := $(BONUS:.c=.o)

ifdef WITH_BONUS
OBJS += $(BNS_OBJS)
else
OBJS += $(MAND_OBJS)
endif

$(NAME) : $(OBJS)
	make -C ../utils
	make -C ../minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBUTIL) $(MLX) -lXext -lX11 -lm

all : $(NAME)

bonus : all
	make WITH_BONUS=1

%.o : %.c $(HEADERFILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ../utils
	make clean -C ../minilibx-linux
	$(RM) $(OBJS) $(MAND_OBJS) $(BNS_OBJS)

fclean : clean
	make fclean -C ../utils
	$(RM) $(NAME) $(MLX)

re : fclean all

PHONY : fclean clean all re