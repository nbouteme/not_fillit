/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:14:33 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/04 13:05:42 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

typedef struct			s_board
{
	unsigned short		tetras[26];
	unsigned char		ntetra;
}						t_board;

typedef struct s_render	t_render;

t_board					*parse_info(char **array);
t_board					*clone_board(t_board *board);
t_render				*resolve(t_board *board);
t_render				*render(t_board *b, int i, int n, t_render *ret);

#endif
