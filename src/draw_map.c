/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:32:44 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 20:13:51 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_two_lines(t_fdf *fdf, t_data *img, int row_i, int col_i)
{
	t_vector	vec;

	vec = fdf->vecs[row_i][col_i];
	if (row_i)
		draw_line(img, vec, fdf->vecs[row_i - 1][col_i], fdf);
	if (col_i)
		draw_line(img, vec, fdf->vecs[row_i][col_i - 1], fdf);
}

static void	my_mlx_string_put(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->mlx, fdf->win, x, y, STR_COLOR, str);
}

static void	put_description(t_fdf *fdf)
{
	my_mlx_string_put(fdf, 740, 900, "Zoom in  : +");
	my_mlx_string_put(fdf, 740, 920, "Zoom out : -");
	my_mlx_string_put(fdf, 440, 900, "Altitude higher : w");
	my_mlx_string_put(fdf, 440, 920, "Altitude lower  : s");
	my_mlx_string_put(fdf, 140, 900, "Translate : h j k l");
	my_mlx_string_put(fdf, 140, 920, "Rotate    : Arrow key");	
}

/*  draw whole map  */
void	draw_map(t_fdf *fdf)
{
	// t_data		img;
	t_vector	vec;
	int			row_i;
	int			col_i;

	fdf->img.img = mlx_new_image(fdf->mlx, WIN_SIZE, WIN_SIZE);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
			&fdf->img.line_length, &fdf->img.endian);
	// system("leaks -q fdf");

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
			draw_two_lines(fdf, &fdf->img, row_i, col_i);
	}
	// mlx_do_key_autorepeaton(fdf->mlx); // 効かない
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	put_description(fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
    mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	// system("leaks -q fdf");

	mlx_loop(fdf->mlx);
}
