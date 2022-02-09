/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:49 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/09 17:33:26 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "./utils.h"

# define SHIFT_MOVE 50
# define ARGC 2
# define WIN_SIZE 800
# define WIN_CENTER 400
# define SCALE_XY 300
# define XY_BASE 5
# define SCALE_Z 0.8
# define ROTATE_RATE 10
# define M_ROTATE_RATE 20
# define ZOOM_RATE 1.3
# define ALTITUDE_RATE 1.3
# define DELTA_RATIO 0.4
# define WHITE 0xEEDDDD
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define STR_COLOR 0xEEAAAA

/*  vector components include color  */
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_vector;

/*  minilibx image data  */
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*  fdf information  */
typedef struct s_fdf {
	t_vector	**vecs;
	t_vector	**flats;
	t_vector	origin;
	t_data		img;
	void		*mlx;
	void		*win;
	int			map_row;
	int			map_col;
}	t_fdf;

/*  keyboard and mouse move  */
enum {
	ON_KEYLEFT = 65361,
	ON_KEYUP = 65362,
	ON_KEYRIGHT = 65363,
	ON_KEYDOWN = 65364,
	ON_KEYW = 119,
	ON_KEYS = 115,
	ON_KEYH = 104,
	ON_KEYJ = 106,
	ON_KEYK = 107,
	ON_KEYL = 108,
	ON_KEYPLUS = 94,
	ON_KEYMINUS = 45,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSERIGHT = 6,
	ON_MOUSELEFT = 7,
	ON_DESTROY = 65307,
};

void		fdf(char *filename);
t_slist		*get_file_map(int fd);
void		set_vectors(t_fdf *fdf, t_slist *file_map);
void		copy_vecs_to_flats(t_fdf *fdf);
void		get_map_size(t_fdf *fdf, t_slist *file_map);
void		free_2d_arr(void **arr, int map_col);
void		free_fdf(t_fdf *fdf, t_slist *file_map, bool is_error);
void		init_vecs(t_fdf *fdf);
void		draw_map(t_fdf *fdf);
void		draw_line(t_data *img, t_vector start, t_vector end);
t_vector	get_internal_vector(t_vector start, t_vector end, double ratio);
int			mouse_hook(int button, int x, int y, t_fdf *fdf);
int			key_hook(int keycode, t_fdf *fdf);
void		update_vecs(t_fdf *fdf, void (*matrix)(t_vector *, t_vector origin, \
					double), double ratio);
void		rotate_horizontally(t_vector *vec, t_vector origin, double radian);
void		rotate_around_y_ordinate(t_vector *vec, t_vector origin, \
							double radian);
void		rotate_around_x_axis(t_vector *vec, t_vector origin, double radian);
void		zoom(t_vector *vec, t_vector origin, double coef);
void		shift_x(t_vector *vec, t_vector origin, double move);
void		shift_y(t_vector *vec, t_vector origin, double move);
void		raise_altitude(t_fdf *fdf, double altitude);
t_vector	extend_vec(t_vector vec, double ratio);
t_vector	sum_vec(t_vector a, t_vector b);
t_vector	diff_vec(t_vector a, t_vector b);
void		show_vec(t_vector vec); // delete

#endif  // FDF_H
