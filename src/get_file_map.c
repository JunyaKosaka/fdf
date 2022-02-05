/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:21:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/05 18:54:55 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    show_file_map(t_slist *map)
{
    printf("show_map\n");
	while (map != NULL)
	{
		printf("%s", map->content);
		map = map->next;
	}
}

t_slist		*get_file_map(int fd)
{
    char	*map_one_line;
    t_slist  *file_map;
    int     response;
    t_slist *new;

    map_one_line = get_next_line(fd);
    // if (map_one_line == NULL)
    //     return (NULL); get_next_lineの対応
	file_map = NULL;
	while (map_one_line != NULL)
	{
        new = slist_new(map_one_line);
        if (new == NULL)
            return (NULL);
		slist_add_back(&file_map, new);
		map_one_line = get_next_line(fd);
        // 失敗なのか最後なのか対応する
	}
    show_file_map(file_map);
    return (file_map);
}
