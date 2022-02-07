/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:43:21 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/07 14:18:58 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "./utils.h"

# define SHIFT_MOVE 50
# define ARGC 2
# define WIN_SIZE 1000
# define WIN_CENTER 500
# define SCALE_XY 300
# define XY_BASE 5
# define SCALE_Z 0.8
# define ROTATE_RATE 10
# define DELTA_RATIO 0.2
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
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
	t_vector	**flats;
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
	ON_KEYHAT = 22,
	ON_KEYV = 9,
	ON_KEYH = 4,
	ON_KEYJ = 38,
	ON_KEYK = 40,
	ON_KEYL = 37,
	ON_KEYPLUS = 24,
	ON_KEYMINUS = 27,
	
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 53,
};

void		fdf(char *filename);
t_slist		*get_file_map(int fd);
t_vector	**get_vectors(t_slist *file_map, t_fdf *fdf);
void	    get_map_size(t_fdf *fdf, t_slist *file_map);
void		free_2d_arr(void **arr, int map_col);
void		free_fdf(t_fdf *fdf, t_slist *file_map, bool is_error);
void		init_vecs(t_fdf *fdf);
void		rotate_horizontally(t_fdf *fdf, double radian);
void		rotate_around_y_ordinate(t_fdf *fdf, double radian);
void		rotate_around_x_axis(t_vector *vec, double radian);
void	    draw_map(t_fdf *fdf);
t_vector    get_internal_vector(t_vector start, t_vector end, double ratio);
int			key_hook(int keycode, t_fdf *fdf);
// void		zoom_map(t_fdf *fdf, double coef);
void		update_vecs(t_fdf *fdf, void (*func)(t_vector *, double), double arg);
void		zoom(t_vector *vec, double coef);

#endif  // FDF_H
