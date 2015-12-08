/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:04:52 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/08 14:12:41 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"

int				ft_sqrt(int n)
{
	int	max;
	int	i;

	max = n / 2;
	i = 0;
	while (i <= max)
		if (i * i >= n)
			return (i);
		else
			++i;
	return (0);
}

void			erase_render(t_render *r, t_point pos, char c)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (r->screen[pos.y + i][pos.x + j] == c)
				r->screen[pos.y + i][pos.x + j] = '.';
	}
}

unsigned short	translate2(char **screen, t_point pos)
{
	int		i;
	char	*c[4];

	i = -1;
	while (++i < 4)
		c[i] = screen[i + pos.y] + pos.x;
	return (translate(c, 0, 0));
}
