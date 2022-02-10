/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:47:42 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/10 10:40:01 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	double	diff_x;
	double	diff_y;
	double	coef;

	coef = M_PI / ROTATE_RATE / 400;
	diff_x = -((x - WIN_MID) - fdf->origin.x);
	diff_y = -((y - WIN_MID) - fdf->origin.y);
	if (button == ON_MOUSEUP)
		update_vecs(fdf, rotate_around_x_axis, M_PI / M_ROTATE_RATE);
	else if (button == ON_MOUSEDOWN)
		update_vecs(fdf, rotate_around_x_axis, -M_PI / M_ROTATE_RATE);
	else if (button == ON_MOUSERIGHT)
		update_vecs(fdf, rotate_around_y_ordinate, -M_PI / M_ROTATE_RATE);
	else if (button == ON_MOUSELEFT)
		update_vecs(fdf, rotate_around_y_ordinate, M_PI / M_ROTATE_RATE);
	else
	{
		update_vecs(fdf, rotate_around_x_axis, diff_y * coef);
		update_vecs(fdf, rotate_around_y_ordinate, diff_x * coef);
	}
	draw_map(fdf);
	return (0);
}

void	key_hook_sub(int keycode, t_fdf *fdf)
{
	if (keycode == ON_KEYH)
		update_vecs(fdf, shift_x, -SHIFT_MOVE);
	else if (keycode == ON_KEYJ)
		update_vecs(fdf, shift_y, SHIFT_MOVE);
	else if (keycode == ON_KEYK)
		update_vecs(fdf, shift_y, -SHIFT_MOVE);
	else if (keycode == ON_KEYL)
		update_vecs(fdf, shift_x, SHIFT_MOVE);
	else if (keycode == ON_KEYPLUS)
		update_vecs(fdf, zoom, ZOOM_RATE);
	else if (keycode == ON_KEYMINUS)
		update_vecs(fdf, zoom, 1 / ZOOM_RATE);
	else if (keycode == ON_KEYW)
		raise_altitude(fdf, ALTITUDE_RATE);
	else if (keycode == ON_KEYS)
		raise_altitude(fdf, 1 / ALTITUDE_RATE);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ON_ESC)
		free_fdf(fdf, NULL, false);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	if (keycode == ON_KEYUP)
		update_vecs(fdf, rotate_around_x_axis, M_PI / ROTATE_RATE);
	else if (keycode == ON_KEYDOWN)
		update_vecs(fdf, rotate_around_x_axis, -M_PI / ROTATE_RATE);
	else if (keycode == ON_KEYRIGHT)
		update_vecs(fdf, rotate_around_y_ordinate, -M_PI / ROTATE_RATE);
	else if (keycode == ON_KEYLEFT)
		update_vecs(fdf, rotate_around_y_ordinate, M_PI / ROTATE_RATE);
	key_hook_sub(keycode, fdf);
	draw_map(fdf);
	return (0);
}
