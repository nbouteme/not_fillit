/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:14:59 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 13:44:07 by nbouteme         ###   ########.fr       */
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
	ft_memcpy(clone->tetras, board->tetras, sizeof(unsigned short) * 26);
	ft_memcpy(clone->position, board->position, sizeof(unsigned short) * 26);
	ft_memcpy(clone->order, board->order, sizeof(unsigned char) * 26);
	return (clone);
}

t_render *resolve(t_board *board)
{

	return tmp;
}

t_render *render(t_board *b, int i, int n, t_render *ret)
{
	int j;
	t_render *good;
	t_render *tmp;

}
