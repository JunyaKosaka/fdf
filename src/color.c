/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:06:28 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/20 13:27:40 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	red(t_vector *vec, t_vector origin, double move)
{
	(void)origin;
	(void)move;
	(*vec).color = RED;
}

void	green(t_vector *vec, t_vector origin, double move)
{
	(void)origin;
	(void)move;
	(*vec).color = GREEN;
}

void	blue(t_vector *vec, t_vector origin, double move)
{
	(void)origin;
	(void)move;
	(*vec).color = BLUE;
}

void	reset_center(t_vector *vec, t_vector origin, double move)
{
	(void)move;
	(*vec).x -= origin.x;
	(*vec).y -= origin.y;
}
