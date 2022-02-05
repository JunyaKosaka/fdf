/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:25:31 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/05 18:25:33 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	*free_one(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}

void	*free_two(char **s1, char **s2)
{
	free_one(s1);
	free_one(s2);
	return (NULL);
}
