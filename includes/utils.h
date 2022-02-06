/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:28:28 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 10:39:43 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

# define STDERR 2
# define FD_MAX 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

/*  string list  */
typedef struct s_slist
{
	char			*content;
	struct s_slist	*next;
}   t_slist;

int		error_handler(void);
char	*get_next_line(int fd, bool *is_ok);
void	*free_one(char **s);
void	*free_two(char **s1, char **s2);
t_slist	*slist_new(char *content);
void	slist_add_back(t_slist **lst, t_slist *new);
t_slist	*slist_last(t_slist *lst);
void	slist_clear(t_slist **lst);
int		slist_size(t_slist *lst);
size_t	count_words(char const *s, char c);
char	**fdf_split(char const *s, char c, int *column);
int		hex_atoi(const char *str);
char	**fdf_split(char const *s, char c, int *words);

#endif  // UTILS_H
