/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:28:29 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 01:59:52 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_horizontally(t_vector *vec, t_vector origin, double radian)
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	src.x -= origin.x;
	src.y -= origin.y;
	dest.x = (src.x * cos(radian)) - (src.y * sin(radian));
	dest.y = (src.x * sin(radian)) + (src.y * cos(radian));
	dest.z = src.z;
	dest.x += origin.x;
	dest.y += origin.y;
	dest.color = src.color;
	*vec = dest;
}

void	rotate_around_y_ordinate(t_vector *vec, t_vector origin, double radian)
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	src.x -= origin.x;
	src.y -= origin.y;
	dest.x = (src.x * cos(radian)) - (src.z * sin(radian));
	dest.y = src.y;
	dest.z = (src.x * sin(radian)) + (src.z * cos(radian));
	dest.x += origin.x;
	dest.y += origin.y;
	dest.color = src.color;
	*vec = dest;
}

void	rotate_around_x_axis(t_vector *vec, t_vector origin, double radian)
{
	t_vector	src;
	t_vector	dest;	

	src = *vec;
	src.x -= origin.x;
	src.y -= origin.y;
	dest.x = src.x;
	dest.y = (src.y * cos(radian)) - (src.z * sin(radian));
	dest.z = (src.y * sin(radian)) + (src.z * cos(radian));
	dest.x += origin.x;
	dest.y += origin.y;
	dest.color = src.color;
	*vec = dest;
}
