/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:47:42 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/21 20:05:33 by jkosaka          ###   ########.fr       */
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
	mlx_destroy_image(fdf->mlx, fdf->img.img);
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
	render_map(fdf);
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
	else if (keycode == ON_KEYZ)
		update_vecs(fdf, zoom, ZOOM_RATE);
	else if (keycode == ON_KEYX)
		update_vecs(fdf, zoom, 1 / ZOOM_RATE);
	else if (keycode == ON_KEYW)
		raise_altitude(fdf, ALTITUDE_RATE);
	else if (keycode == ON_KEYS)
		raise_altitude(fdf, 1 / ALTITUDE_RATE);
	else if (keycode == ON_KEYC)
		fdf->cabinet ^= true;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ON_ESC)
		free_fdf(fdf, NULL, false);
	printf("keycode: %d\n", keycode);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	if (keycode == ON_KEYUP)
		update_vecs(fdf, rotate_around_x_axis, M_PI / ROTATE_RATE);
	else if (keycode == ON_KEYDOWN)
		update_vecs(fdf, rotate_around_x_axis, -M_PI / ROTATE_RATE);
	else if (keycode == ON_KEYRIGHT)
		update_vecs(fdf, rotate_around_y_ordinate, -M_PI / ROTATE_RATE);
	else if (keycode == ON_KEYLEFT)
		update_vecs(fdf, rotate_around_y_ordinate, M_PI / ROTATE_RATE);
	else if (keycode == ON_KEYR)
		update_vecs(fdf, red, false);
	else if (keycode == ON_KEYG)
		update_vecs(fdf, green, false);
	else if (keycode == ON_KEYB)
		update_vecs(fdf, blue, false);
	else if (keycode == ON_KEYA)
		update_vecs(fdf, reset_color, false);
	else if (keycode == ON_KEYO)
		update_vecs(fdf, reset_center, false);
	key_hook_sub(keycode, fdf);
	render_map(fdf);
	return (0);
}
