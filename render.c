/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:16:40 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/04 11:40:11 by nbouteme         ###   ########.fr       */
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
	while (++i < 26)
		r->screen[i] = ft_memset(ft_strnew(27), '.', 26);
	r->w = 0;
	r->h = 0;
	return (r);
}

t_render	*copy_render(t_render *r)
{
	t_render	*ret;
	int			i;

	i = -1;
	ret = malloc(sizeof(t_render));
	while (++i < 26)
		ret->screen[i] = ft_strsub(r->screen[i], 0, 26);
	ret->s = r->s;
	ret->w = r->w;
	ret->h = r->h;
	return (ret);
}

void		delete_render(t_render *d)
{
	int	i;

	if (!d)
		return ;
	i = -1;
	while (++i < 26)
		free(d->screen[i]);
	free(d);
}

int			place(t_render *r, t_u16 tetra, t_point pos, char c)
{
	int		i;
	short	curr;
	char	**cur;
	char	**tet;

	cur = chunk(r->screen, pos);
	if ((tetra & (curr = translate(cur, 0, 0))) == 0)
	{
		tet = tetra2str(tetra, c);
		merge_chunk(tet, cur);
		set_chunk(r->screen, tet, pos);
		measure_render(r);
		i = 1;
	}
	else
		i = 0;
	free(cur);
	return (i);
}
