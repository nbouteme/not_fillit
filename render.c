/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:16:40 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/04 21:25:38 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "render.h"
#include "tetra.h"
#include "block.h"

t_render	*new_render(void)
{
	t_render	*r;
	int			i;

	i = -1;
	r = malloc(sizeof(t_render));
	while (++i < 11)
		r->screen[i] = ft_memset(ft_strnew(12), '.', 11);
	r->s = 0;
	return (r);
}

t_render	*copy_render(t_render *r)
{
	t_render	*ret;
	int			i;

	i = -1;
	ret = malloc(sizeof(t_render));
	while (++i < 11)
		ret->screen[i] = ft_strsub(r->screen[i], 0, 11);
	ret->s = r->s;
	return (ret);
}

void		delete_render(t_render *d)
{
	int	i;

	if (!d)
		return ;
	i = -1;
	while (++i < 11)
		free(d->screen[i]);
	free(d);
}

void		merge_chunk(char **tetra, char **screen, t_point pos)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (screen[pos.y + i][pos.x + j] == '.')
				screen[pos.y + i][pos.x + j] = tetra[i][j];
	}
}

int			place(t_render *r, t_u16 tetra, t_point pos, char c)
{
	int				i;
	unsigned short	curr;
	char			**tet;

	if ((tetra & (curr = translate2(r->screen, pos))) == 0)
	{
		tet = tetra2str(tetra, c);
		merge_chunk(tet, r->screen, pos);
		measure_render(r);
		i = 1;
	}
	else
		i = 0;
	return (i);
}
