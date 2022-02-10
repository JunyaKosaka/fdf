/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:54:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/10 11:15:04 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	copy_vecs_to_flats(t_fdf *fdf)
{
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

static void	set_z_and_color(t_vector *vec, char **elements, int num)
{
	(*vec).z = ft_atoi(elements[0]);
	if (num == 2)
		(*vec).color = hex_atoi(elements[1]);
}

static	void	free_fdf_and_elements(t_fdf *fdf, t_slist *file_map, \
									char **line_elements)
{
	free_2d_arr((void **)line_elements, -1);
	free_fdf(fdf, file_map, true);
}

void	set_vectors(t_fdf *fdf, t_slist *file_map)
{
	int			num;
	char		**line_elements;
	char		**dot_elements;
	int			row_i;
	int			col_i;

	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		printf("^^^57\n");
		line_elements = ft_split(file_map->content, ' ');
		if (!line_elements)
			free_fdf(fdf, file_map, true);
		col_i = -1;
		printf("^^^62\n");
		while (++col_i < fdf->map_col)
		{
			printf("^^^65\n");
			dot_elements = fdf_split(line_elements[col_i], ',', &num);
			if (dot_elements == NULL)
				free_fdf_and_elements(fdf, file_map, line_elements);
			set_z_and_color(&(fdf->vecs[row_i][col_i]), dot_elements, num);
			free_2d_arr((void **)dot_elements, -1);
		}
		free_2d_arr((void **)line_elements, -1);
		file_map = file_map->next;
	}
}
