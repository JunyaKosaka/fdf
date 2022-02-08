/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:54:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 23:25:43 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	copy_vecs_to_flats(t_fdf *fdf)
{
	t_vector	**flats;
	int			row_i;
	int			col_i;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			fdf->flats[row_i][col_i] = fdf->vecs[row_i][col_i];
			fdf->flats[row_i][col_i].z = 0;
		}
	}
}

void	set_xy_color(t_fdf *fdf)
{
	int	row_i;
	int	col_i;
	
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			fdf->vecs[row_i][col_i].x = col_i;
			fdf->vecs[row_i][col_i].y = row_i;
			fdf->vecs[row_i][col_i].color = WHITE;
		}
	}
}

void	set_vectors(t_fdf *fdf, t_slist *file_map)
{
	int			element_num;
	char		**line_elements;
	char		**dot_elements;
	int			row_i;
	int			col_i;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		line_elements = ft_split(file_map->content, ' ');
		if (!line_elements)
			free_fdf(fdf, file_map, true);
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			// fdf->vecs[row_i][col_i].x = col_i;
			// fdf->vecs[row_i][col_i].y = row_i;
			dot_elements = fdf_split(line_elements[col_i], ',', &element_num);
			if (dot_elements == NULL)
				free_fdf(fdf, file_map, true);
			// set_vectors_sub(fdf, )
			fdf->vecs[row_i][col_i].z = ft_atoi(dot_elements[0]);
			// 書き換える
			// fdf->vecs[row_i][col_i].color = 0xffffff;
			if (element_num == 2)
			{
				fdf->vecs[row_i][col_i].color = hex_atoi(dot_elements[1]);
				if (fdf->vecs[row_i][col_i].color == -1)
					free_fdf(fdf, file_map, true);
				//free関数を上に適用
			}
			free_2d_arr((void **)dot_elements, -1);
		}
		free_2d_arr((void **)line_elements, -1);
		file_map = file_map->next;
	}
}
