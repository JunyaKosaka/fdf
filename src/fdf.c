/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:04:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/05 17:08:13 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf(char *filename)
{
	// int		    fd;
	// t_llist	    *file_map;
    // t_fdf       fdf;
    // // char        ***elements;

	// fd = open(argv[1], R_OK);
	// if(fd == -1)
	// 	return (error_handler());
    // fdf.mlx = mlx_init();
    // fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, " FDF ");

    // file_map = get_file_map(fd);
    // if (file_map == NULL)
    //     return (error_handler());
    // init_fdf(&fdf);
    // // elements = get_element(file_map);
    // // if (is_valid_file(elements) == false)
    // //     return (error_handler());
    // fdf.vecs = get_vectors(file_map, &fdf);
    // get_map_size(&fdf, file_map);
    // fdf.vecs = change_center(fdf.vecs, fdf.map_row, fdf.map_col);
    // line_lstclear(&file_map);
    // draw_map(&fdf);

    system("leaks fdf");
}
