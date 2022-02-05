/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 01:12:07 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 01:15:28 by jkosaka          ###   ########.fr       */
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

static size_t	word_count(char const *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			ret++;
		s++;
	}
	return (ret);
}

char	**fdf_split(char const *s, char c, int *words)
{
	char	**ret;

	if (!s)
		return (NULL);
	*words = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (*words + 1));
	if (!ret)
		return (NULL);
	ret[*words] = NULL;
	ret = rec(ret, s, c, 0);
	if (!ret)
		free(ret);
	return (ret);
}
