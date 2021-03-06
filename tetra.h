/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:17:02 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/07 16:42:56 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRA_H
# define TETRA_H

# include "block.h"

t_tetraptr		tetra2str(unsigned short tetra, char c);
unsigned short	parse_tetra(char **array);

#endif
