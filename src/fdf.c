/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:48:41 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 14:33:35 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->vecs = NULL;
	fdf->flats = NULL;
	fdf->origin.x = 0;
	fdf->origin.y = 0;
	fdf->origin.z = 0;
}

// void	prepare_vecs(t_fdf *fdf, t_slist *file_map)
// {
// 	t_vector	**vecs;
// 	t_vector	**flats;
// 	int			row_i;
// 	int			col_i;

// 	vecs = (t_vector **)malloc(sizeof(t_vector *) * fdf->map_row);
// 	flats = (t_vector **)malloc(sizeof(t_vector *) * fdf->map_row);
// 	if (!vecs || !flats)
// 		free_fdf(fdf, file_map, true);
// 	row_i = -1;
// 	while (++row_i < fdf->map_row)	

	
// }

void	fdf(char *filename)
{
	int			fd;
	t_fdf       fdf;
	t_slist		*file_map;

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
		free_fdf(&fdf, file_map, true);
	init_fdf(&fdf);
	get_map_size(&fdf, file_map);
	// prepare_vecs(&fdf, file_map);
	// 列数判定
	fdf.vecs = get_vectors(&fdf, file_map);
	slist_clear(&file_map);
	init_vecs(&fdf);
	draw_map(&fdf);

	// system("leaks fdf");
}
