/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:48:41 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 01:19:22 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->vecs = NULL;
	fdf->origin.x = 0;
	fdf->origin.y = 0;
	fdf->origin.z = 0;
}

void	fdf(char *filename)
{
	int			fd;
	t_fdf       fdf;
	t_slist		*file_map;
	// char		***elements;

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
	//	 return (error_handler());
	get_map_size(&fdf, file_map);
	fdf.vecs = get_vectors(&fdf, file_map);
	// fdf.flats = get_flats(&fdf, file_map);
	slist_clear(&file_map);
	init_vecs(&fdf);
	draw_map(&fdf);

	// system("leaks fdf");
}
