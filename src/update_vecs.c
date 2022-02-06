/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:05:15 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 10:31:34 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_horizontally(t_fdf *fdf, double radian)
{
	int			row_i;
	int			col_i;
	t_vector	src_vec;
	t_vector	dest_vec;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			src_vec = fdf->vecs[row_i][col_i];
			dest_vec.x = (src_vec.x * cos(radian)) - (src_vec.y * sin(radian));
			dest_vec.y = (src_vec.x * sin(radian)) + (src_vec.y * cos(radian));
			dest_vec.z = src_vec.z;
			dest_vec.color = src_vec.color;	
			fdf->vecs[row_i][col_i] = dest_vec;
		}
	}
}

// t_vector	rotate_around_y_ordinate(t_vector src_vec, double radian)
// {
// 	t_vector	dest_vec;

// 	dest_vec.x = (src_vec.x * cos(radian)) + (src_vec.z * sin(radian));
// 	dest_vec.y = src_vec.y;
// 	dest_vec.z = -(src_vec.x * sin(radian)) + (src_vec.z * cos(radian));
// 	dest_vec.color = src_vec.color;
// 	return (dest_vec);
// }

// t_vector	rotate_around_x_axis(t_vector src_vec, double radian)//  ここ
// {
// 	t_vector	dest_vec;

// 	dest_vec.x = src_vec.x;
// 	dest_vec.y = (src_vec.y * cos(radian)) - (src_vec.z * sin(radian));
// 	dest_vec.z = (src_vec.y * sin(radian)) + (src_vec.z * cos(radian));
// 	dest_vec.color = src_vec.color;
// 	return (dest_vec);
// }

// t_vector	rotate_vector(t_vector src_vec, t_fdf *fdf)
// {
//     t_vector    dest_vec;
//     t_vector    temp_vec;

//     dest_vec = src_vec;
//     // temp_vec = rotate_horizontally(src_vec, fdf->radian_xy);
//     temp_vec = rotate_around_y_ordinate(src_vec, fdf->radian_zx);
//     temp_vec = rotate_around_x_axis(temp_vec, fdf->radian_yz);
//     dest_vec.x = temp_vec.x;
//     dest_vec.y = temp_vec.y;
//     return (dest_vec);
// }
