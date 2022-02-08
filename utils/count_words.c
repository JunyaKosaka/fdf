/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:49:53 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 20:30:56 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*  count words separated by a delimiter  */
size_t	count_words(char const *s, char c)
{
	size_t	ret;

	if (!s)
		return (0);
	ret = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			ret++;
		s++;
	}
	return (ret);
}
