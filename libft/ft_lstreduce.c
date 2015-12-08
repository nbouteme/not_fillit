/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:22:21 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/26 19:49:50 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstreduce(const t_list *l, const t_list *init,
					t_list *(*f)(const t_list *, const t_list*))
{
	t_list *acc;
	t_list *tmp;

	acc = ft_lstnew(init->content, init->content_size);
	while (l)
	{
		tmp = f(acc, l);
		free(acc);
		acc = tmp;
		l = l->next;
	}
	return (acc);
}
