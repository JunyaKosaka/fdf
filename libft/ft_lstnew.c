/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:35:32 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/31 19:53:12 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *new;
// 	char	*content;

// 	content = (char *)malloc(sizeof(char) * 10);
// 	memset(content, 'a', 10);
// 	new = ft_lstnew(content);
// 	printf("%s\n", (char *)new->content);
// 	return (0);
// }
