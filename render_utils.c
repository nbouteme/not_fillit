/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:18:16 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 11:59:22 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

#include "render.h"
#include "block.h"

void print_render(t_render *r)
{
	int i;

	i = 0;
	while(i < r->s)
	{
		write(1, r->screen[i++], r->s);
		ft_putchar(10);
	}
}

int measure_render(t_render *r)
{
	int a;
	int b;

	a = 26;
	b = 26;
	while(--a && col_empty(r->screen, a, 26))
		;
	while(--b && line_empty(r->screen, b, 26))
		;
	r->s = a < b ? b : a;
	r->w = a + 1;
	r->h = b + 1;
	return (++r->s);
}

char *flatten(t_render *r)
{
	char *s;
	char *d;
	int i;
	int j;
	char c;

	c = 'A';
	s = ft_strnew(27);
	d = s;
	i = -1;
	while(++i < r->h)
	{
		j = -1;
		while(++j < r->w)
		{
			if(r->screen[i][j] != '.' && !strchr(s, r->screen[i][j]))
				*d++ = r->screen[i][j];
		}
	}
	return s;
}

int predcmp(char *a, char *b)
{
	char c;
	int i;
	int j;

	c = 'A';
	while(c < 'Z')
	{
		i = ft_strchr(a, c) - a;
		j = ft_strchr(b, c) - b;
		if (i < 0 || j < 0)
			break ;
		if (i != j)
			return (i - j);
		++c;
	}
	return (0);
}
