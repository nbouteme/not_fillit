/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:16:40 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 15:42:32 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "render.h"
#include "tetra.h"
#include "block.h"

t_render *new_render()
{
	t_render *r;
	int i;

	i = -1;
	r = malloc(sizeof(t_render));
	while(++i < 26)
		r->screen[i] = ft_memset(malloc(26), '.', 26);
	r->w = 0;
	r->h = 0;
	return r;
}

int render_cmp(t_render *a, t_render *b)
{
	char	*sa;
	char	*sb;
	int		res;

	if (a->s != b->s)
		return (a->s - b->s);
	sa = flatten(a);
	sb = flatten(b);
	res = predcmp(sa, sb);
	free(sa);
	free(sb);
	if (!res)
	{
		if (a->h != b->h)
			return (a->h - b->h);
		if (a->w != b->w)
			return (a->w - b->w);
	}
	return (res);
}

t_render *copy_render(t_render *r)
{
	t_render *ret;
	int i;

	i = -1;
	ret = malloc(sizeof(t_render));
	while(++i < 26)
		ret->screen[i] = ft_strsub(r->screen[i], 0, 26);
	ret->s = r->s;
	ret->w = r->w;
	ret->h = r->h;
	return ret;
}

void delete_render(t_render *d)
{
	int i;

	if(!d)
		return ;
	i = -1;
	while(++i < 26)
		free(d->screen[i]);
	free(d);
}

void place(t_render *r, unsigned short tetra, t_point pos, char c)
{
	int i;
	short curr;
	char **cur;
	char **tet;

	cur = chunk(r->screen, position, i);
	if((tetra & (curr = translate(cur, 0, 0))) == 0)
	{
		tet = tetra2str(tetra, c);
		merge_chunk(tet, cur);
		set_chunk(r->screen, tet, position, i);
		measure_render(r);
	}
	free(cur);
}
