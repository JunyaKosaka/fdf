/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:48:41 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/10 10:57:36 by jkosaka          ###   ########.fr       */
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

void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_SIZE, WIN_SIZE, " FDF ");
	fdf->img.img = mlx_new_image(fdf->mlx, WIN_SIZE, WIN_SIZE);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
			&fdf->img.line_length, &fdf->img.endian);
}

void	prepare_vecs(t_fdf *fdf, t_slist *file_map)
{
	int			row_i;
	int			col_i;

	fdf->vecs = (t_vector **)malloc(sizeof(t_vector *) * fdf->map_row);
	fdf->flats = (t_vector **)malloc(sizeof(t_vector *) * fdf->map_row);
	if (!fdf->vecs || !fdf->flats)
		free_fdf(fdf, file_map, true);
	row_i = -1;
	while (++row_i < fdf->map_row)
	{
		fdf->vecs[row_i] = (t_vector *)malloc(sizeof(t_vector) * fdf->map_col);
		fdf->flats[row_i] = (t_vector *)malloc(sizeof(t_vector) * fdf->map_col);
		if (!(fdf->vecs[row_i]) || !(fdf->flats[row_i]))
			free_fdf(fdf, file_map, true);
		col_i = -1;
		while (++col_i < fdf->map_col)
		{
			fdf->vecs[row_i][col_i].x = col_i;
			fdf->vecs[row_i][col_i].y = row_i;
			fdf->vecs[row_i][col_i].color = WHITE;
		}
	}
}

void	fdf(char *filename)
{
	int			fd;
	t_fdf		fdf;
	t_slist		*file_map;

	fd = open(filename, R_OK);
	if (fd == -1)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}
	init_fdf(&fdf);
	file_map = get_file_map(fd);
	if (!file_map)
		free_fdf(&fdf, file_map, true);
	get_map_size(&fdf, file_map);
	prepare_vecs(&fdf, file_map);
	set_vectors(&fdf, file_map);
	slist_clear(&file_map);
	init_vecs(&fdf);
	init_mlx(&fdf);
	draw_map(&fdf);
}
