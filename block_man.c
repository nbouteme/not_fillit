/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:09:27 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/03 10:45:20 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "render.h"

char **chunk(char **block, t_point pos)
{
	char **ret;
	int i;

	i = -1;
	ret = malloc(4 * sizeof(char *));
	while(++i < 4)
		ret[i] = ft_strsub(block[pos.y + i], pos.x, 4);
	return ret;
}

void set_chunk(char **block, char **chunk, t_point pos)
{
	int i;

	i = -1;
	while(++i < 4)
		ft_strncpy(block[pos.y + i] + pos.x, chunk[i], 4);
}

void merge_chunk(char **tet, char **cur)
{
	int i;
	int j;

	i = -1;
	while(++i < 4)
	{
		j = -1;
		while(++j < 4)
			if(tet[i][j] == '.')
				tet[i][j] = cur[i][j];
		free(cur[i]);
	}
}
