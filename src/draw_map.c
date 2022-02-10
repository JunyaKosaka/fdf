/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:32:44 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/10 14:58:38 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_two_lines(t_fdf *fdf, t_data *img, int row_i, int col_i)
{
	t_vector	vec;

	vec = fdf->vecs[row_i][col_i];
	if (row_i)
		draw_line(img, vec, fdf->vecs[row_i - 1][col_i]);
	if (col_i)
		draw_line(img, vec, fdf->vecs[row_i][col_i - 1]);
}

static void	my_mlx_string_put(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->mlx, fdf->win, x, y, STR_COLOR, str);
}

static void	put_description(t_fdf *fdf)
{
	my_mlx_string_put(fdf, WIN_MID + 150, WIN_SIZE - 120, "Zoom in  : Z");
	my_mlx_string_put(fdf, WIN_MID + 150, WIN_SIZE - 100, "Zoom out : X");
	my_mlx_string_put(fdf, WIN_MID - 50, WIN_SIZE - 120, "Altitude + : W");
	my_mlx_string_put(fdf, WIN_MID - 50, WIN_SIZE - 100, "Altitude - : S");
	my_mlx_string_put(fdf, WIN_MID - 250, WIN_SIZE - 120, \
					"Translate : H J K L");
	my_mlx_string_put(fdf, WIN_MID - 250, WIN_SIZE - 100, \
					"Rotate    : Arrow key");
}

static void	destroy(t_fdf *fdf)
{
	free_fdf(fdf, NULL, false);
}

/*  draw whole map  */
void	draw_map(t_fdf *fdf)
{
	int			row_i;
	int			col_i;

	
	fdf->img.img = mlx_new_image(fdf->mlx, WIN_SIZE, WIN_SIZE);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
			&fdf->img.line_length, &fdf->img.endian);
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
			draw_two_lines(fdf, &fdf->img, row_i, col_i);
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	put_description(fdf);
	mlx_hook(fdf->win, ON_DESTROY, ON_DESTROY, destroy, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
}
