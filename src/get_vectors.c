/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:11:22 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 14:02:27 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	**get_vectors(t_slist *file_map, t_fdf *fdf)
{
	t_vector	**vecs;
    int			row;
	int			element_num;
    char		**one_line_element;
	char		**one_pixel_element;
    int			row_i;
    int			col_i;

    row = slist_size(file_map);
    vecs = (t_vector **)malloc(sizeof(t_vector *) * (row + 1));
    if (!vecs)
        free_fdf(fdf, file_map, true);
    vecs[row] = NULL;
    row_i = -1;
    while (++row_i < fdf->map_row)
    {
        one_line_element = ft_split(file_map->content, ' ');
        vecs[row_i] = (t_vector *)malloc(sizeof(t_vector) * fdf->map_col);
        if (one_line_element == NULL || vecs[row_i] == NULL)
            free_fdf(fdf, file_map, true);
		col_i = -1;
        while(++col_i < fdf->map_col)
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
					exit(1);
				//free関数を上に適用
			}
			free_2d_arr((void **)one_pixel_element, -1);
        }
		free_2d_arr((void **)one_line_element, -1);
        file_map = file_map->next;
    }
	return (vecs);
}
