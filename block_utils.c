/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:04:52 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 10:09:19 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"

unsigned short recognize(char **block)
{
	int x;
	int y;
	int i;
	unsigned short result;
	const unsigned short tetras[] = { 0xF000, 0xCC00, 0xE400, 0xE800,
									  0xE200, 0xC600, 0x6C00, 0x8888,
									  0xCC00, 0x4C40, 0xC440, 0x4480,
									  0x4C80, 0x8C40, 0xF000, 0xCC00,
									  0x4E00, 0x8E00, 0x2E00, 0xC600,
									  0x6C00, 0x8888, 0xCC00, 0x8C80,
									  0x88C0, 0xC880, 0x4C80, 0x8C40,
									  0x0000};

	x = 0;
	y = 0;
	i = 0;
	while (col_empty(block, x, 4))
		++x;
	while (line_empty(block, y, 4))
		++y;
	result = translate(block, x, y);
	while(i < 28)
		if(tetras[i++] == result)
			return (result);
	return (0);
}

unsigned short translate(char **block, int xshift, int yshift)
{
	unsigned short result;
	int i;
	int j;
	char c;

	result = 0;
	i = 0;
	while (i < 4 - yshift)
	{
		j = 0;
		c = 0;
		while(j < 4 - xshift)
		{
			c |= (block[i + yshift][j + xshift] != '.') << (3 - j);
			++j;
		}
		result |= c << (12 - (i << 2));
		++i;
	}
	return (result);
}

int line_empty(char **block, int col, int n)
{
	int i;

	i = 0;
	while(i < n)
		if(block[col][i] != '.')
			return (0);
		else
			++i;
	return (1);
}

int col_empty(char **block, int l, int n)
{
	int i;

	i = 0;
	while(i < n)
		if(block[i][l] != '.')
			return (0);
		else
			++i;
	return (1);
}
