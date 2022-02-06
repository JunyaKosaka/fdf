/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:11:22 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 08:25:59 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector    **get_vectors(t_slist *file_map, t_fdf *fdf)
{
	t_vector	**vectors;
    int			row;
    int			column;
	int			element_num;
    char		**one_line_element;
	char		**one_pixel_element;
    int			row_i;
    int			col_i;

    row = slist_size(file_map);
    vectors = (t_vector **)malloc(sizeof(t_vector *) * (row + 1));
    if (!vectors)
        free_fdf(fdf, file_map, true);
    vectors[row] = NULL;
    row_i = 0;
    while (file_map)
    {
        one_line_element = fdf_split(file_map->content, ' ', &column);
        vectors[row_i] = (t_vector *)malloc(sizeof(t_vector) * column);
        if (one_line_element == NULL || vectors[row_i] == NULL)
            free_fdf(fdf, file_map, true);
		col_i = 0;
        while(col_i < column)
        {
			vectors[row_i][col_i].x = col_i;
			vectors[row_i][col_i].y = row_i;
			one_pixel_element = fdf_split(one_line_element[col_i], ',', &element_num);
            if (one_pixel_element == NULL)
                free_fdf(fdf, file_map, true); 
            vectors[row_i][col_i].z = ft_atoi(one_pixel_element[0]);
			vectors[row_i][col_i].color = 0xffffff;
			if (element_num == 2)
			{
				vectors[row_i][col_i].color = hex_atoi(one_pixel_element[1]);
				if (vectors[row_i][col_i].color == -1)
					exit(1);
				//free関数を上に適用
			}
			free_2d_arr((void **)one_pixel_element, -1);
	        // printf("%d, %d | ", vectors[row_i][col_i].z, vectors[row_i][col_i].color);
            col_i++;
        }
        // printf("\n");
		free_2d_arr((void **)one_line_element, -1);
        file_map = file_map->next;
        row_i++;
    }
    return (vectors);
}

