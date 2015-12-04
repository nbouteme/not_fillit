/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:16:40 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/04 13:44:57 by nbouteme         ###   ########.fr       */
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

int			place(t_render *r, t_u16 tetra, t_point pos, char c)
{
	int		i;
	short	curr;
	char	**cur;
	char	**tet;

	//cur = chunk(r->screen, pos);
	//if ((tetra & (curr = translate(cur, 0, 0))) == 0)
	if ((tetra & (curr = translate(r->screen, pos.x, pos.y))) == 0)
	{
		tet = tetra2str(tetra, c);
		char *cur[4];
		cur[0] = r->screen[pos.y] + pos.x;
		cur[1] = r->screen[pos.y+1] + pos.x;
		cur[2] = r->screen[pos.y+2] + pos.x;
		cur[3] = r->screen[pos.y+3] + pos.x;
		merge_chunk(tet, cur);
		measure_render(r);
		i = 1;
	}
	else
		i = 0;
	free(cur);
	return (i);
}
