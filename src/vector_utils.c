/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:23:45 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 23:56:32 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	extend_vec(t_vector vec, double ratio)
{
	vec.x *= ratio;
	vec.y *= ratio;
	vec.z *= ratio;
	return (vec);
}

t_vector	sum_vec(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vector	diff_vec(t_vector a, t_vector b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}
