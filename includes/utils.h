/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:28:28 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/05 17:01:21 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include "../libft/libft.h"

# define STDERR 2
# define FD_MAX 256
# define SHIFT_MOVE 60
# define ARGC 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

/*  char list  */
typedef struct s_clist
{
	char			*content;
	struct s_clist	*next;
}   t_clist;

/*  vector components include color  */
typedef struct s_vector
{
    double	x;
    double	y;
    double	z;
	int		color;
}	t_vector;

/*  minilibx image data  */
typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}	t_data;

/*  fdf information  */
typedef struct	s_fdf {
	t_vector	**vecs;
	void		*mlx;
	void		*win;
	int			map_row;
	int			map_col;
	int			shift_x;
	int			shift_y;
}	t_fdf;

/*  keyboard and mouse move  */
enum {
	ON_KEYDOWN = 125,
	ON_KEYUP = 126,
	ON_KEYRIGHT = 124,
	ON_KEYLEFT = 123,
	ON_KEYGREATER = 47,
	ON_KEYLESS = 43,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 53,
};

int	error_handler(void);

#endif  // UTILS_H
