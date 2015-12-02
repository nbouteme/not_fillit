/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:16:06 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 15:19:53 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RENDER_H
# define	RENDER_H


typedef struct	s_render
{
	char		*screen[26];
	int			s;
	int			w;
	int			h;
}				t_render;

typedef struct	s_point
{
	int y;
	int x;
}				t_point;

t_render *new_render();
int render_cmp(t_render *a, t_render *b);
t_render *copy_render(t_render *r);
void delete_render(t_render *d);
void place(t_render *r, unsigned short tetra, unsigned short position, char c);

void print_render(t_render *r);
int measure_render(t_render *r);
char *flatten(t_render *r);
int predcmp(char *a, char *b);

#endif
