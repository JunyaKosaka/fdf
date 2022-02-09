/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:05:15 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/09 14:00:35 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(t_vector *vec, t_vector origin, double coef)
{
	t_vector	src;
	t_vector	dest;

	(void)origin;
	src = *vec;
	dest.x = src.x * coef;
	dest.y = src.y * coef;
	dest.z = src.z * coef;
	dest.color = src.color;
	*vec = dest;
}

void	shift_x(t_vector *vec, t_vector origin, double move)
{
	(void)origin;
	(*vec).x += move;
}

void	shift_y(t_vector *vec, t_vector origin, double move)
{
	(void)origin;
	(*vec).y += move;
}

void	update_vecs(t_fdf *fdf, void (*matrix)(t_vector *, t_vector origin, \
				double), double ratio)
{
	int			row_i;
	int			col_i;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			matrix(&fdf->vecs[row_i][col_i], fdf->origin, ratio);
			matrix(&fdf->flats[row_i][col_i], fdf->origin, ratio);
		}
	}
	if (matrix == shift_x)
		fdf->origin.x += ratio;
	if (matrix == shift_y)
		fdf->origin.y += ratio;
}

void	raise_altitude(t_fdf *fdf, double ratio)
{
	int			row_i;
	int			col_i;	
	t_vector	base;
	t_vector	peak;
	t_vector	vec;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			peak = fdf->vecs[row_i][col_i];
			base = fdf->flats[row_i][col_i];
			vec = diff_vec(peak, base);
			vec = extend_vec(vec, ratio);
			fdf->vecs[row_i][col_i] = sum_vec(base, vec);
		}
	}
}
