/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:47:42 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/07 14:40:01 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ON_DESTROY)
		free_fdf(fdf, NULL, false);
	printf("key: %d\n", keycode);
	if (keycode == ON_KEYUP)
		update_vecs(fdf, rotate_around_x_axis, M_PI / ROTATE_RATE);
	if (keycode == ON_KEYDOWN)
		update_vecs(fdf, rotate_around_x_axis, -M_PI / ROTATE_RATE);
	if (keycode == ON_KEYRIGHT)
		rotate_around_y_ordinate(fdf, -M_PI / ROTATE_RATE);
	if (keycode == ON_KEYLEFT)
		rotate_around_y_ordinate(fdf, M_PI / ROTATE_RATE);
	if (keycode == ON_KEYH)
		fdf->shift_x += SHIFT_MOVE;
	if (keycode == ON_KEYJ)
		fdf->shift_y -= SHIFT_MOVE;
	if (keycode == ON_KEYK)
		fdf->shift_y += SHIFT_MOVE;
	if (keycode == ON_KEYL)
		fdf->shift_x -= SHIFT_MOVE;
	if (keycode == ON_KEYPLUS)
		update_vecs(fdf, zoom, 1.3);
	if (keycode == ON_KEYMINUS)
		update_vecs(fdf, zoom, 0.8);
	draw_map(fdf);
	return (0);
}