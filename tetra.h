/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:17:02 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/03 10:12:33 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRA_H
# define TETRA_H

char			**tetra2str(unsigned short tetra, char c);
unsigned short	parse_tetra(char **array);

#endif
