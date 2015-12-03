/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:14:59 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/03 14:25:20 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>

#include "board.h"
#include "render.h"
#include "tetra.h"
#include "sys_utils.h"
#include "utils.h"

t_board *parse_info(char **array)
{
	t_board *board;

	board = malloc(sizeof(t_board));
	ft_bzero(board, sizeof(t_board));
	board->ntetra = 0;
	board->tetras[board->ntetra] = parse_tetra(array);
	if(!board->tetras[board->ntetra])
		quit_properly();
	++board->ntetra;
	array += 7;
	while(array[0] && ft_strcmp(array[0], "\n\n") == 0)
	{
		board->tetras[board->ntetra] = parse_tetra(++array);
		if(!board->tetras[board->ntetra])
			quit_properly();
		++board->ntetra;
		if(board->ntetra > 26)
			quit_properly();
		array += 7;
	}
	if(array[1])
		quit_properly();
	return (board);
}

t_board *clone_board(t_board *board)
{
	t_board *clone;

	clone = malloc(sizeof(t_board));
	ft_memcpy(clone->tetras, board->tetras, sizeof(((t_board*)0)->tetras));
	ft_memcpy(clone->position, board->position, sizeof(((t_board*)0)->position));
	ft_memcpy(clone->order, board->order, sizeof(((t_board*)0)->order));
	return (clone);
}

#include <assert.h>

t_render *render_ctl(int cmd, t_render *r)
{
	static t_render *solution = 0;

	if(r && cmd == 0 && (!solution || solution->s > r->s))
		solution = r;

	return solution;
}

void quit_gracefully(t_render *r)
{
	print_render(r);
	exit(0);
}

t_render *rec_solve(t_board *b, int n, t_render *r, int max)
{
	if(n == b->ntetra)
	{
		render_ctl(0, r);
		if(r->s <= max)
			quit_gracefully(r);
		return r;
	}
	for(int i = 0; i < max; ++i)
		for(int j = 0; j < max; ++j)
		{
			t_render *tmp = copy_render(r);
			if(place(tmp, b->tetras[n], (t_point){i, j}, 'A' + n))
				if(tmp->s <= max + 1)
					rec_solve(b, n + 1, tmp, max);
		}
	return 0;
}

t_render *resolve(t_board *board)
{
	int n;
	n = ft_sqrt(board->ntetra * 4);
	rec_solve(board, 0, new_render(), n);
	return render_ctl(1, 0);
}
