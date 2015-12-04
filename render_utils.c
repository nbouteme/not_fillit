/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:18:16 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/04 15:16:55 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

#include "render.h"
#include "block.h"

void	print_render(t_render *r)
{
	int i;

	i = 0;
	while (i < r->s)
	{
		write(1, r->screen[i++], r->s);
		ft_putchar(10);
	}
}

int		measure_render(t_render *r)
{
	int a;
	int b;

	a = 11;
	b = 11;
	while (--a && col_empty(r->screen, a, 11))
		;
	while (--b && line_empty(r->screen, b, 11))
		;
	r->s = a < b ? b : a;
	return (++r->s);
}
