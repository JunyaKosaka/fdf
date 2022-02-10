/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:20:30 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/10 11:08:59 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_2d_arr(void **arr, int limit)
{
	int	i;

	if (!arr)
		return ;
	if (limit == -1)
		limit = INT_MAX;
	i = -1;
	while (arr[++i] && i < limit)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

void	free_fdf(t_fdf *fdf, t_slist *file_map, bool is_error)
{
	if (file_map)
		slist_clear(&file_map);
	if (fdf->vecs)
		free_2d_arr((void **)fdf->vecs, fdf->map_row);
	if (fdf->flats)
		free_2d_arr((void **)fdf->flats, fdf->map_row);
	printf("42\n");
	mlx_destroy_window(fdf->mlx, fdf->win);
	printf("43\n");
	free(fdf->mlx);
	fdf->mlx = NULL;
	if (is_error)
		exit(error_handler());
	exit(0);
}
