/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:04:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 11:15:42 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    init_fdf(t_fdf *fdf)
{
    fdf->vecs = NULL;
    fdf->shift_x = 0;
    fdf->shift_y = 0;
}

void	fdf(char *filename)
{
	int		    fd;
    t_fdf       fdf;
	t_slist	    *file_map;
    // char        ***elements;

	fd = open(filename, R_OK);
	if (fd == -1)
	{
		perror(filename);
		exit(EXIT_FAILURE); // directoryの時
	}
    fdf.mlx = mlx_init();
    fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, " FDF ");
    file_map = get_file_map(fd);
    if (!file_map)
    {
        error_handler();
        exit(EXIT_FAILURE);
    }
    init_fdf(&fdf);
    // elements = get_element(file_map);
    // if (is_valid_file(elements) == false)
    //     return (error_handler());
    fdf.vecs = get_vectors(file_map, &fdf);
    get_map_size(&fdf, file_map);
    init_vecs(&fdf);
    slist_clear(&file_map);
    draw_map(&fdf);

    // system("leaks fdf");
}
