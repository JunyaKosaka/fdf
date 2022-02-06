/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:34:32 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 11:11:12 by jkosaka          ###   ########.fr       */
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

    row_i = -1;
    while (++row_i < fdf->map_row)
    {
        col_i = -1;
        while (++col_i < fdf->map_col)
        {
			fdf->vecs[row_i][col_i].x *= SCALE_XY;
			fdf->vecs[row_i][col_i].y *= SCALE_XY;
			fdf->vecs[row_i][col_i].z *= SCALE_Z;
        }
    }
}

void	init_vecs(t_fdf *fdf)
{
    change_center(fdf);
	scale_up(fdf);
	rotate_horizontally(fdf, M_PI / 4);
}
