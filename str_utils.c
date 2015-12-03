/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:12:30 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/03 16:49:12 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <stdlib.h>

static int	count_tokens(const char *str, char c)
{
	int			i;
	const char	*s;
	const char	*d;

	i = 0;
	s = str;
	while (*str == c)
		++str;
	s = str + 1;
	while (*str)
	{
		while (*s && *s != c)
			++s;
		d = s;
		while (*s && *s == c)
			++s;
		if (d != s)
			++i;
		str = s++;
		++i;
	}
	return (i);
}

char		**ft_strtok(const char *str, char c)
{
	const char	*s;
	const char	*d;
	char		**ret;
	int			i;

	ret = (char**)malloc(sizeof(char*) * (count_tokens(str, c) + 1));
	while (*str == c)
		++str;
	s = str;
	i = 0;
	while (*str)
	{
		while (*s && *s != c)
			++s;
		ret[i] = ft_strncpy(ft_strnew(s - str + 1), str, s - str);
		d = s;
		while (*s && *s == c)
			++s;
		i += !!ret[i];
		if (d != s)
			ret[i++] = ft_strncpy(ft_strnew(s - d + 1), d, s - d);
		str = s++;
	}
	ret[i] = 0;
	return (ret);
}
