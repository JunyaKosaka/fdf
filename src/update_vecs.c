/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:05:15 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 01:03:05 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_horizontally(t_vector *vec, t_vector origin, double radian)
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	src.x -= origin.x;
	src.y -= origin.y;
	dest.x = (src.x * cos(radian)) - (src.y * sin(radian));
	dest.y = (src.x * sin(radian)) + (src.y * cos(radian));
	dest.z = src.z;
	dest.x += origin.x;
	dest.y += origin.y;
	dest.color = src.color;
	*vec = dest;
}

void	rotate_around_y_ordinate(t_vector *vec, t_vector origin, double radian)
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	src.x -= origin.x;
	src.y -= origin.y;
	dest.x = (src.x * cos(radian)) - (src.z * sin(radian));
	dest.y = src.y;
	dest.z = (src.x * sin(radian)) + (src.z * cos(radian));
	dest.x += origin.x;
	dest.y += origin.y;
	dest.color = src.color;
	*vec = dest;
}

void	rotate_around_x_axis(t_vector *vec, t_vector origin, double radian)	
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	src.x -= origin.x;
	src.y -= origin.y;
	dest.x = src.x;
	dest.y = (src.y * cos(radian)) - (src.z * sin(radian));
	dest.z = (src.y * sin(radian)) + (src.z * cos(radian));
	dest.x += origin.x;
	dest.y += origin.y;
	dest.color = src.color;
	*vec = dest;
}

void	zoom(t_vector *vec, t_vector origin, double coef)
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	src.x -= origin.x;
	src.y -= origin.y;
	dest.x = src.x * coef;
	dest.y = src.y * coef;
	dest.z = src.z * coef;
	dest.x += origin.x;
	dest.y += origin.y;
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

t_vector	extend_vec(t_vector vec, double ratio)
{
	vec.x *= ratio;
	vec.y *= ratio;
	vec.z *= ratio;
	return (vec);
}

t_vector	sum_vec(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vector	diff_vec(t_vector a, t_vector b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

void	show_vec(t_vector vec)
{
	printf("vec: %.2f %.2f %.2f\n", vec.x, vec.y, vec.z);
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
