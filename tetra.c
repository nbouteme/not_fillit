/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:57:38 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/07 16:12:10 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "block.h"

t_tetraptr		tetra2str(unsigned short tetra, char c)
{
	int			i;
	int			j;
	static char	ret[4][4];

	i = 4;
	ft_memset(ret, '.', sizeof(ret));
	while (i--)
	{
		j = -1;
		while (j++ < 3)
			ret[3 - i][j] = ((tetra & (0xF << (i << 2))) >> (i << 2) &
							(1 << (3 - j))) ? c : '.';
	}
	return (&ret);
}

unsigned short	parse_tetra(char **array)
{
	char	*tetra[4];
	int		i;
	int		j;

	tetra[0] = array[0];
	tetra[1] = array[2];
	tetra[2] = array[4];
	tetra[3] = array[6];
	i = -1;
	while (++i < 4)
	{
		j = -1;
		if (!tetra[i] || ft_strlen(tetra[i]) != 4)
			return (0);
		while (++j < 4)
			if (tetra[i][j] != '.' && tetra[i][j] != '#')
				return (0);
	}
	return (recognize(tetra));
}
