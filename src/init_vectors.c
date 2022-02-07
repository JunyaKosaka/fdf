/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:34:32 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/07 10:30:23 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	**change_center(t_fdf *fdf)
{
    int row_i;
    int col_i;
    double row_center;
    double col_center;

    row_center = fdf->map_row / 2;
    col_center = fdf->map_col / 2;
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
    int 	row_i;
    int 	col_i;
	double	divide;

	divide = min(fdf->map_row, fdf->map_col);
    row_i = -1;
    while (++row_i < fdf->map_row)
    {
        col_i = -1;
        while (++col_i < fdf->map_col)
        {
			fdf->vecs[row_i][col_i].y *= (double)SCALE_XY / divide + XY_BASE;
			fdf->vecs[row_i][col_i].x *= (double)SCALE_XY / divide + XY_BASE;
			fdf->vecs[row_i][col_i].z *= (double)SCALE_Z;
        }
    }
}

void	init_vecs(t_fdf *fdf)
{
    change_center(fdf);
	scale_up(fdf);
	rotate_horizontally(fdf, M_PI / 4);
    update_vecs(fdf, rotate_around_x_axis, acos((double)1 / sqrt(5)));
    // rotate_around_x_axis(fdf, );
}
