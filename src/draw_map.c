/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:32:44 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 02:19:30 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*  draw dot on minilibx image. return true if can draw  */
static bool	draw_dot(t_vector vec, t_data *img, t_fdf *fdf)
{
	int	mlx_x;
	int	mlx_y;

	mlx_x = vec.x + WIN_CENTER;
	mlx_y = vec.y + WIN_CENTER;
	if (mlx_x <= 0 || WIN_SIZE <= mlx_x)
		return (false);
	if (mlx_y <= 0 || WIN_SIZE <= mlx_y)
		return (false);
	my_mlx_pixel_put(img, mlx_x, mlx_y, vec.color);
	return (true);
}

/*  draw line between two vectors  */
static void	draw_line(t_data *img, t_vector start, t_vector end, t_fdf *fdf)
{
	double		ratio;
	double		diff;
	t_vector	target;

	if (!draw_dot(start, img, fdf) && !draw_dot(end, img, fdf))
		return ;
	diff = max_abs_3(end.x - start.x, end.y - start.y, end.z - start.z);
	ratio = 0;
	while (ratio <= 1)
	{
		target = get_internal_vector(start, end, ratio);
		draw_dot(target, img, fdf);
		ratio += (double)DELTA_RATIO / diff;
	}
}

void	draw_two_lines(t_fdf *fdf, t_data *img, int row_i, int col_i)
{
	t_vector	vec;

	vec = fdf->vecs[row_i][col_i];
	if (row_i)
		draw_line(img, vec, fdf->vecs[row_i - 1][col_i], fdf);
	if (col_i)
		draw_line(img, vec, fdf->vecs[row_i][col_i - 1], fdf);
}

void	my_mlx_string_put(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->mlx, fdf->win, x, y, STR_COLOR, str);
}

void	put_description(t_fdf *fdf)
{
	my_mlx_string_put(fdf, 740, 900, "Zoom in  : +");
	my_mlx_string_put(fdf, 740, 920, "Zoom out : -");
	my_mlx_string_put(fdf, 440, 900, "Altitude higher : ^");
	my_mlx_string_put(fdf, 440, 920, "Altitude lower  : v");
	my_mlx_string_put(fdf, 140, 900, "Translate : h j k l");
	my_mlx_string_put(fdf, 140, 920, "Rotate    : Arrow key");	
}

/*  draw whole map  */
void	draw_map(t_fdf *fdf)
{
	t_data		img;
	t_vector	vec;
	int			row_i;
	int			col_i;

	img.img = mlx_new_image(fdf->mlx, WIN_SIZE, WIN_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
			draw_two_lines(fdf, &img, row_i, col_i);
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.img, 0, 0);
	put_description(fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
    // mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
}
