/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:24:47 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/04 21:26:21 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int				ft_sqrt(int n);
void			erase_render(t_render *r, t_point pos, char c);
unsigned short	translate2(char **screen, t_point pos);

#endif
