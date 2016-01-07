/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:10:36 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/07 16:42:29 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_UTILS_H
# define SYS_UTILS_H

# define B_SIZE 4096

char	*readfile(int fd, int (*check)(char *));
void	quit_properly(void);
char	**ft_strtok(const char *str, char c);
int		check_input(char *s);

#endif
