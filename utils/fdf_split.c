/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 01:12:07 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/10 16:56:25 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	**rec(char **container, char const *s, char c, size_t ind)
{
	char const	*head;

	while (*s && *s == c)
		s++;
	if (!(*s))
		return (container);
	head = s;
	while (*s && *s != c)
		s++;
	head = ft_substr(head, 0, s - head);
	if (!head)
		return (NULL);
	container = rec(container, s, c, ind + 1);
	if (!container)
	{
		free((void *)head);
		return (NULL);
	}
	container[ind] = (char *)head;
	return (container);
}

char	**ft_split(char const *s, char c, int *words)
{
	char	**container;
	char	**ret;

	if (!s)
		return (NULL);
	*words = word_count(s, c);
	container = (char **)malloc(sizeof(char *) * (*words + 1));
	if (!container)
		return (NULL);
	container[words] = NULL;
	ret = rec(container, s, c, 0);
	if (!ret)
		free(container);
	return (ret);
}
