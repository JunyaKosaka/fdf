/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:54:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 14:34:42 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	**get_flats(t_fdf *fdf)
{
	t_vector	**flats;
	int			row_i;
	int			col_i;

	// flats = (t_vector **)malloc(sizeof(t_vector *) * fdf->map_row);
	// if (!flats)
	// 	free_fdf(fdf, NULL, true);
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		// flats[row_i] = (t_vector *)malloc(sizeof(t_vector) * fdf->map_col);
		// if (!flats[row_i])
		// {
		// 	free_2d_arr((void **)flats, fdf->map_row);
		// 	free_fdf(fdf, NULL, true);
		// }
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			flats[row_i][col_i] = fdf->vecs[row_i][col_i];
			flats[row_i][col_i].z = 0;
		}
	}
	return (flats);
}

t_vector	**get_vectors(t_fdf *fdf, t_slist *file_map)
{
	t_vector	**vecs;
	int			element_num;
	char		**one_line_element;
	char		**one_pixel_element;
	int			row_i;
	int			col_i;

	// vecs = (t_vector **)malloc(sizeof(t_vector *) * fdf->map_row);
	// if (!vecs)
	// 	free_fdf(fdf, file_map, true);
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		one_line_element = ft_split(file_map->content, ' ');
		// vecs[row_i] = (t_vector *)malloc(sizeof(t_vector) * fdf->map_col);
		if (one_line_element == NULL || vecs[row_i] == NULL)
			free_fdf(fdf, file_map, true);
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			vecs[row_i][col_i].x = col_i;
			vecs[row_i][col_i].y = row_i;
			one_pixel_element = fdf_split(one_line_element[col_i], ',', &element_num);
			if (one_pixel_element == NULL)
				free_fdf(fdf, file_map, true);
			// printf("%s\n", one_pixel_element[0]);
			vecs[row_i][col_i].z = ft_atoi(one_pixel_element[0]);
			// 書き換える
			vecs[row_i][col_i].color = 0xffffff;
			if (element_num == 2)
			{
				vecs[row_i][col_i].color = hex_atoi(one_pixel_element[1]);
				if (vecs[row_i][col_i].color == -1)
					free_fdf(fdf, file_map, true);
				//free関数を上に適用
			}
			free_2d_arr((void **)one_pixel_element, -1);
		}
		free_2d_arr((void **)one_line_element, -1);
		file_map = file_map->next;
	}
	return (vecs);
}
