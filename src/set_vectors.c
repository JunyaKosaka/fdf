/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:54:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 14:50:11 by jkosaka          ###   ########.fr       */
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

void	set_vectors(t_fdf *fdf, t_slist *file_map)
{
	int			element_num;
	char		**one_line_element;
	char		**one_pixel_element;
	int			row_i;
	int			col_i;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		one_line_element = ft_split(file_map->content, ' ');
		if (one_line_element == NULL || fdf->vecs[row_i] == NULL)
			free_fdf(fdf, file_map, true);
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			fdf->vecs[row_i][col_i].x = col_i;
			fdf->vecs[row_i][col_i].y = row_i;
			one_pixel_element = fdf_split(one_line_element[col_i], ',', &element_num);
			if (one_pixel_element == NULL)
				free_fdf(fdf, file_map, true);
			// printf("%s\n", one_pixel_element[0]);
			fdf->vecs[row_i][col_i].z = ft_atoi(one_pixel_element[0]);
			// 書き換える
			fdf->vecs[row_i][col_i].color = 0xffffff;
			if (element_num == 2)
			{
				fdf->vecs[row_i][col_i].color = hex_atoi(one_pixel_element[1]);
				if (fdf->vecs[row_i][col_i].color == -1)
					free_fdf(fdf, file_map, true);
				//free関数を上に適用
			}
			free_2d_arr((void **)one_pixel_element, -1);
		}
		free_2d_arr((void **)one_line_element, -1);
		file_map = file_map->next;
	}
}
