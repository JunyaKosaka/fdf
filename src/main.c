/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:57:41 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 01:20:44 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

__attribute__((destructor))
    static void destructor() {
    system("leaks -q fdf");
}

int	main(int argc, char **argv)
{
	if (argc != ARGC)
		exit(error_handler());
	fdf(argv[1]);
	return (0);
}
