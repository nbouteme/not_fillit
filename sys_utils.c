/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:12:00 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/03 15:23:40 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

#include "sys_utils.h"

void	quit_properly(void)
{
	write(2, "error\n", 6);
	exit(1);
}

int check_input(char *s)
{
	static char *auth = ".#\n";
	while(*s)
		if(ft_strindexof(auth, *s) == -1)
			return 0;
		else
			++s;
	return 1;
}

char	*readfile(int fd, int (*check)(char *))
{
	char	*buf;
	char	*tmp;
	char	*ret;
	int		n;

	ret = ft_strnew(1);
	buf = ft_strnew(B_SIZE + 1);
	while ((n = read(fd, buf, B_SIZE)) > 0)
	{
		if(!check(buf))
			return 0;
		tmp = ret;
		ft_bzero(buf + n, B_SIZE - n);
		ret = ft_strjoin(ret, buf);
		free(tmp);
	}
	free(buf);
	return (ret);
}
