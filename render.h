/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:16:06 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/04 11:40:45 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef unsigned short	t_u16;

typedef struct			s_render
{
	char				*screen[26];
	int					s;
	int					w;
	int					h;
}						t_render;

typedef struct			s_point
{
	int y;
	int x;
}						t_point;

t_render				*new_render();
t_render				*copy_render(t_render *r);
void					delete_render(t_render *d);
int						place(t_render *r, t_u16 tetra,
							t_point position, char c);
void					print_render(t_render *r);
int						measure_render(t_render *r);

#endif
