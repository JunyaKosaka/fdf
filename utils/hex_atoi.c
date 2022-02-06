/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 01:16:51 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 11:15:20 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	is_space(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

static int	is_hexnum(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	c = ft_toupper(c);
	return ('A' <= c && c <= 'F');
}

/*  convert one digit to int  */
static int	convert_to_int(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	c = ft_toupper(c);
	return (10 + (c - 'A'));
}

/*  hexadecimal atoi  */
int	hex_atoi(const char *str)
{
	long	ret;

	ret = 0;
	while (is_space(*str))
		str++;
	if (ft_strncmp(str, "0x", 2) != 0)
		return (-1);
	str += 2;
	if (!is_hexnum(str[0]))
		return (-1);
	while (is_hexnum(*str))
	{
		ret = ret * 16 + convert_to_int(*str);
		if (ret > INT_MAX)
			return (-1);
		str++;
	}
	return ((int)ret);
}
