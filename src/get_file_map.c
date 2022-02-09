/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:21:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/09 18:16:03 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_map_size(t_fdf *fdf, t_slist *file_map)
{
	fdf->map_row = slist_size(file_map);
	fdf->map_col = count_words(file_map->content, ' ');
}

static	void	*free_one_line(char *one_line)
{
	free(one_line);
	one_line = NULL;
	return (NULL);
}

t_slist	*get_file_map(int fd)
{
	t_slist	*file_map;
	t_slist	*new;
	char	*one_line;
	bool	is_ok;
	size_t	column;

	printf("36\n");
	one_line = get_next_line(fd, &is_ok);
	if (!is_ok || !one_line)
		return (NULL);
	printf("40\n");
	column = count_words(one_line, ' ');
	file_map = NULL;
	while (one_line != NULL)
	{
		printf("45\n");
		new = slist_new(one_line);
		if (!new)
			return (NULL);
		slist_add_back(&file_map, new);
		one_line = get_next_line(fd, &is_ok);
		if (!is_ok || (one_line && column != count_words(one_line, ' ')))
		{
			slist_clear(&file_map);
			return (free_one_line(one_line));
		}
	}
	return (file_map);
}
