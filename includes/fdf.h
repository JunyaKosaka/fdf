/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:43:21 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 11:37:00 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "./utils.h"

# define SHIFT_MOVE 60
# define ARGC 2
# define WIN_SIZE 1000
# define WIN_CENTER 500
# define SCALE_XY 300
# define SCALE_Z 0.8
# define DELTA_RATIO 0.01

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

void		fdf(char *filename);
t_slist		*get_file_map(int fd);
t_vector    **get_vectors(t_slist *file_map, t_fdf *fdf);
void	    get_map_size(t_fdf *fdf, t_slist *file_map);
void		free_2d_arr(void **arr, int map_col);
void		free_fdf(t_fdf *fdf, t_slist *file_map, bool is_error);
void		init_vecs(t_fdf *fdf);
void		rotate_horizontally(t_fdf *fdf, double radian);
void	    draw_map(t_fdf *fdf);
t_vector    get_internal_vector(t_vector start, t_vector end, double ratio);

#endif  // FDF_H
