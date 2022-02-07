/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:05:15 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/07 20:23:30 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_horizontally(t_fdf *fdf, double radian)
{
	int			row_i;
	int			col_i;
	t_vector	src;
	t_vector	dest;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			src = fdf->vecs[row_i][col_i];
			dest.x = (src.x * cos(radian)) - (src.y * sin(radian));
			dest.y = (src.x * sin(radian)) + (src.y * cos(radian));
			dest.z = src.z;
			dest.color = src.color;
			fdf->vecs[row_i][col_i] = dest;
		}
	}
}

void	rotate_around_y_ordinate(t_vector *vec, double radian)	
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	dest.x = (src.x * cos(radian)) - (src.z * sin(radian));
	dest.y = src.y;
	dest.z = (src.x * sin(radian)) + (src.z * cos(radian));
	dest.color = src.color;
	*vec = dest;
}

void	rotate_around_x_axis(t_vector *vec, double radian)	
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	dest.x = src.x;
	dest.y = (src.y * cos(radian)) - (src.z * sin(radian));
	dest.z = (src.y * sin(radian)) + (src.z * cos(radian));
	dest.color = src.color;
	*vec = dest;
}

void	zoom(t_vector *vec, double coef)
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	dest.x = src.x * coef;
	dest.y = src.y * coef;
	dest.z = src.z * coef;
	dest.color = src.color;
	*vec = dest;
}

void	shift_x(t_vector *vec, double move)
{
	(*vec).x += move;
}

void	shift_y(t_vector *vec, double move)
{
	(*vec).y += move;
}

void	update_vecs(t_fdf *fdf, void (*matrix)(t_vector *, double), \
					double ratio)
{
	int			row_i;
	int			col_i;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			matrix(&fdf->vecs[row_i][col_i], ratio);
		}
	}
	if (matrix == shift_x)
	{
		printf("114\n");
		fdf->origin_x += ratio;
	}
	if (matrix == shift_y)
		fdf->origin_y += ratio;
}

// void	gain_altitude(t_fdf *fdf, double altitude)
// {
// 	int			row_i;
// 	int			col_i;
// 	t_vector	src;
// 	t_vector	dest;
// 	t_vector	base;

// 	row_i = -1;
// 	while (++row_i < fdf->map_row)
// 	{
// 		col_i = -1;
// 		while (++col_i < fdf->map_col)
// 		{
// 			src = fdf->vecs[row_i][col_i];
// 			dest.x = src.x;
// 			dest.y = (src.y * cos(radian)) - (src.z * sin(radian));
// 			dest.z = (src.y * sin(radian)) + (src.z * cos(radian));
// 			dest.color = src.color;	
// 			fdf->vecs[row_i][col_i] = dest;
// 		}
// 	}
// }

// t_vector	rotate_around_x_axis(t_vector src, double radian)//  ここ
// {
// 	t_vector	dest;

// 	dest.x = src.x;
// 	dest.y = (src.y * cos(radian)) - (src.z * sin(radian));
// 	dest.z = (src.y * sin(radian)) + (src.z * cos(radian));
// 	dest.color = src.color;
// 	return (dest);
// }

// t_vector	rotate_vector(t_vector src, t_fdf *fdf)
// {
//     t_vector    dest;
//     t_vector    temp_vec;

//     dest = src;
//     // temp_vec = rotate_horizontally(src, fdf->radian_xy);
//     temp_vec = rotate_around_y_ordinate(src, fdf->radian_zx);
//     temp_vec = rotate_around_x_axis(temp_vec, fdf->radian_yz);
//     dest.x = temp_vec.x;
//     dest.y = temp_vec.y;
//     return (dest);
// }
