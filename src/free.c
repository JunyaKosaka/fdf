/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:20:30 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/07 23:50:04 by jkosaka          ###   ########.fr       */
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
	slist_clear(&file_map);
	free_2d_arr((void **)fdf->vecs, fdf->map_row);
	free_2d_arr((void **)fdf->flats, fdf->map_row);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->mlx);
	fdf->mlx = NULL;
	if (is_error)
		exit(error_handler());
	exit(0);
}
