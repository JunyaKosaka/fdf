/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_internal_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:33:12 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 16:39:05 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*  ratio : 1 - ratio  */
t_vector	get_internal_vector(t_vector start, t_vector end, double ratio)
{
	t_vector	target;
	double		s;
	double		t;
	int			color;

	s = 1 - ratio;
	t = ratio;
	target.x = s * start.x + t * end.x;
	target.y = s * start.y + t * end.y;
	target.z = s * start.z + t * end.z;
	color = (int)(s * (start.color & RED) + t * (end.color & RED)) & RED;
	color += (int)(s * (start.color & GREEN) + t * (end.color & GREEN)) & GREEN;
	color += (int)(s * (start.color & BLUE) + t * (end.color & BLUE)) & BLUE;
	target.color = color;
	return (target);
}
