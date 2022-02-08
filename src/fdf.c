/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:48:41 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 17:50:11 by jkosaka          ###   ########.fr       */
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

void	prepare_vecs(t_fdf *fdf, t_slist *file_map)
{
	t_vector	**vecs;
	t_vector	**flats;
	int			row_i;
	int			col_i;

	vecs = (t_vector **)malloc(sizeof(t_vector *) * fdf->map_row);
	flats = (t_vector **)malloc(sizeof(t_vector *) * fdf->map_row);
	if (!vecs || !flats)
		free_fdf(fdf, file_map, true);
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		col_i = -1;
		vecs[row_i] = (t_vector *)malloc(sizeof(t_vector) * fdf->map_col);
		flats[row_i] = (t_vector *)malloc(sizeof(t_vector) * fdf->map_col);
		if (!(vecs[row_i]) || !(flats[row_i]))
		{
			free_2d_arr((void **)vecs, fdf->map_col);
			free_2d_arr((void **)flats, fdf->map_col);
			free_fdf(fdf, file_map, true);
		}
	}
	fdf->vecs = vecs;
	fdf->flats = flats;
}

void	fdf(char *filename)
{
	int			fd;
	t_fdf       fdf;
	t_slist		*file_map;
	t_data		img;

	fd = open(filename, R_OK);
	if (fd == -1)
	{
		perror(filename);
		exit(EXIT_FAILURE); // directoryの時
	}
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, " FDF ");
	// img.img = mlx_new_image(fdf.mlx, WIN_SIZE, WIN_SIZE);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	// 		&img.line_length, &img.endian);
	file_map = get_file_map(fd);
	if (!file_map)
		free_fdf(&fdf, file_map, true);
	init_fdf(&fdf);
	get_map_size(&fdf, file_map);
	prepare_vecs(&fdf, file_map);
	// 列数判定
	set_vectors(&fdf, file_map);
	slist_clear(&file_map);
	init_vecs(&fdf);
	draw_map(&fdf);
}
