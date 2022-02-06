/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:20:30 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 08:21:55 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_2d_arr(void **arr, int map_col)
{
	int	i;

	if (!arr)
		return ;
	if (map_col == -1)
		map_col = INT_MAX;
	i = 0;
	while (arr[i] && i < map_col)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_fdf(t_fdf *fdf, t_slist *file_map, bool is_error)
{
	slist_clear(&file_map);
	free_2d_arr((void **)fdf->vecs, fdf->map_col);
	mlx_destroy_window(fdf->mlx, fdf->win);
  	free(fdf->mlx);
  	fdf->mlx = NULL;
	if (is_error)
		exit(error_handler());
	exit(0);
}
