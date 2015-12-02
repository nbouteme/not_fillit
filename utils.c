/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:04:52 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 10:11:48 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(int n)
{
	int max;
	int i;

	max = n / 2;
	i = 0;
	while(i < max)
	{
		if(i * i >= n)
			return i;
		++i;
	}
	return 0;
}

__int128 huge_fact(unsigned int n)
{
	if(n <= 1)
		return (n);
	return (n * huge_fact(n - 1));
}


void sw(unsigned char  *a, unsigned char  *b)
{
	unsigned char t;
	t = *a;
	*a = *b;
	*b = t;
}

void set_next_perm(unsigned char *p, int n)
{
	int i = n - 1;
	while(p[i - 1] >= p[i])
		--i;
	int j = n;
	while(p[j-1] <= p[i-1])
		--j;
	sw(&p[i-1], &p[j-1]);
	++i;
	j = n;
	while(i < j)
		sw(&p[i++ - 1], &p[j-- - 1]);
}
