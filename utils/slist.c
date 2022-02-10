/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:06 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/10 14:41:57 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_slist	*slist_new(char *content)
{
	t_slist	*ret;

	ret = (t_slist *)malloc(sizeof(t_slist));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

void	slist_add_back(t_slist **lst, t_slist *new)
{
	t_slist	*t_last;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		t_last = slist_last(*lst);
		t_last->next = new;
	}
}

t_slist	*slist_last(t_slist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	slist_clear(t_slist **lst)
{
	t_slist	*cur;
	t_slist	*prev;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev->content);
		free(prev);
	}
	*lst = NULL;
}

int	slist_size(t_slist *lst)
{
	int	ret;

	if (!lst)
		return (0);
	ret = 0;
	while (lst->next)
	{
		ret++;
		lst = lst->next;
	}
	return (ret);
}
