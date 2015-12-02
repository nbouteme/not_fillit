/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:09:27 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 11:58:46 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char **chunk(char **block, int x, int y)
{
	char **ret;
	int i;

	i = -1;
	ret = malloc(4 * sizeof(char *));
	while(++i < 4)
		ret[i] = ft_strsub(block[y + i], x, 4);
	return ret;
}

void set_chunk(char **block, char **chunk, int x, int y)
{
	int i;

	i = -1;
	while(++i < 4)
		ft_strncpy(block[y + i] + x, chunk[i], 4);
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
	free(cur);
}
