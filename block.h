/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:07:20 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/07 16:42:09 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
# define BLOCK_H

# include "render.h"

typedef	char	(*t_tetraptr)[4][4];

t_u16			recognize(char **block);
t_u16			translate(char **block, int xshift, int yshift);
char			**chunk(char **block, t_point pos);
void			set_chunk(char **block, char **chunk, t_point pos);
void			merge_chunk(t_tetraptr tet, char **cur, t_point pos);
int				col_empty(char **block, int l, int n);
int				line_empty(char **block, int col, int n);
unsigned short	translate2(char **screen, t_point pos);

#endif
