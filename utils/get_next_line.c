/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:23:39 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/08 23:59:03 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static char	*join_words(char **s1, const char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!(*s1) || !s2)
		return (free_one(s1));
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret)
		return (free_one(s1));
	ft_strlcpy(ret, *s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, s2, total_len + 1);
	free_one(s1);
	return (ret);
}

static char	*get_one_line_core(char **save, size_t len)
{
	char	*ret;
	char	*temp;

	if (!len || !(*save))
		return (free_one(save));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (free_one(save));
	ft_strlcpy(ret, *save, len + 1);
	temp = NULL;
	if (*((*save) + len))
		temp = ft_strdup((*save) + len);
	free(*save);
	*save = temp;
	return (ret);
}

static char	*get_one_line(char **save, int fd, ssize_t read_bytes)
{
	if (!read_bytes)
		return (get_one_line_core(&save[fd], ft_strlen(save[fd])));
	return (get_one_line_core(&save[fd], \
			ft_strchr(save[fd], '\n') - save[fd] + 1));
}

static char	*init_save(char *s)
{
	if (!s)
		s = ft_strdup("");
	return (s);
}

char	*get_next_line(int fd, bool *is_ok)
{
	static char	*save[FD_MAX] = {NULL};
	char		*buff;
	ssize_t		read_bytes;

	if (fd < 0 || FD_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	*is_ok = false;
	buff = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
		return (free_two(&save[fd], &buff));
	save[fd] = init_save(save[fd]);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(save[fd], '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_two(&save[fd], &buff));
		buff[read_bytes] = '\0';
		save[fd] = join_words(&save[fd], buff);
		if (!save[fd])
			return (free_one(&buff));
	}
	*is_ok = true;
	free_one(&buff);
	return (get_one_line(save, fd, read_bytes));
}
