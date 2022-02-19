/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:23:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/20 01:31:22 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	change_center(t_fdf *fdf)
{
	int		row_i;
	int		col_i;
	double	row_center;
	double	col_center;

	row_center = (double)(fdf->map_row - 1) / 2;
	col_center = (double)(fdf->map_col - 1) / 2;
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			fdf->vecs[row_i][col_i].x -= col_center;
			fdf->vecs[row_i][col_i].y -= row_center;
		}
	}
}

static void	scale_up(t_fdf *fdf)
{
	int		row_i;
	int		col_i;
	double	divide;

	divide = min(fdf->map_row, fdf->map_col);
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			fdf->vecs[row_i][col_i].x *= (double)SCALE_XY / divide + XY_BASE;
			fdf->vecs[row_i][col_i].y *= (double)SCALE_XY / divide + XY_BASE;
			fdf->vecs[row_i][col_i].z *= (double)SCALE_Z;
		}
	}
}

/*  initialize vecs and copy from vecs to flats  */
void	init_vecs(t_fdf *fdf)
{
	change_center(fdf);
	scale_up(fdf);
	copy_vecs_to_flats(fdf);
	update_vecs(fdf, rotate_horizontally, M_PI_4);
	update_vecs(fdf, rotate_around_x_axis, acos((double)1 / sqrt(5)));
}
