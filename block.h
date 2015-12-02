/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:07:20 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 11:28:08 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BLOCK_H
# define	BLOCK_H

unsigned short recognize(char **block);
int col_empty(char **block, int l, int n);
int line_empty(char **block, int col, int n);
unsigned short translate(char **block, int xshift, int yshift);
char **chunk(char **block, int x, int y);
void set_chunk(char **block, char **chunk, int x, int y);
void merge_chunk(char **tet, char **cur);

#endif
