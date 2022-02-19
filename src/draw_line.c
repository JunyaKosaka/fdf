/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:21:37 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/20 01:49:44 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*  draw dot on minilibx image. return true if can draw  */
static bool	draw_dot(t_vector vec, t_data *img, bool is_cabinet)
{
	int	mlx_x;
	int	mlx_y;

	mlx_x = vec.x + WIN_MID;
	mlx_y = vec.y + WIN_MID;
	if (is_cabinet)
	{
		mlx_x -= vec.z * 20; 
		mlx_y += vec.z * 20; 
	}
	if ()
	if (mlx_x <= 0 || WIN_SIZE <= mlx_x)
		return (false);
	if (mlx_y <= 0 || WIN_SIZE <= mlx_y)
		return (false);
	my_mlx_pixel_put(img, mlx_x, mlx_y, vec.color);
	return (true);
}

/*  draw line between two vectors  */
void	draw_line(t_data *img, t_vector start, t_vector end, bool is_cabinet)
{
	double		ratio;
	double		diff;
	t_vector	target;

	if (!draw_dot(start, img) && !draw_dot(end, img))
		return ;
	diff = max_abs_3(end.x - start.x, end.y - start.y, end.z - start.z);
	ratio = 0;
	while (ratio <= 1)
	{
		target = get_internal_vector(start, end, ratio);
		draw_dot(target, img, is_cabinet);
		ratio += (double)DELTA_RATIO / diff;
	}
}
