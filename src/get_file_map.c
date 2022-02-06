/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:21:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 08:34:50 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    show_file_map(t_slist *map) // delete
{
    printf("show_map\n");
	while (map != NULL)
	{
		printf("%s", map->content);
		map = map->next;
	}
}

void    get_map_size(t_fdf *fdf, t_slist *file_map)
{
    fdf->map_row = slist_size(file_map);
	fdf->map_col = count_words(file_map->content, ' ');
}

t_slist		*get_file_map(int fd)
{
    char	*map_one_line;
    t_slist	*file_map;
    bool	is_ok;
    t_slist *new;

    map_one_line = get_next_line(fd, &is_ok);
    if (!is_ok)
        return (NULL);
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
    // show_file_map(file_map);
    return (file_map);
}
