/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:21:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 17:50:36 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	show_file_map(t_slist *map) // delete
{
	while (map != NULL)
	{
		printf("%s", map->content);
		map = map->next;
	}
}

void	get_map_size(t_fdf *fdf, t_slist *file_map)
{
	fdf->map_row = slist_size(file_map);
	fdf->map_col = count_words(file_map->content, ' ');
}

t_slist	*get_file_map(int fd)
{
	t_slist	*file_map;
	t_slist	*new;
	char	*map_one_line;
	bool	is_ok;
	size_t	column;

	map_one_line = get_next_line(fd, &is_ok);
	if (!is_ok)
		return (NULL);
	column = count_words(map_one_line, ' ');
	file_map = NULL;
	while (map_one_line != NULL)
	{
		new = slist_new(map_one_line);
		if (!new)
			return (NULL);
		slist_add_back(&file_map, new);
		map_one_line = get_next_line(fd, &is_ok);
		if (!is_ok)
			return (NULL);
	}
	return (file_map);
}
