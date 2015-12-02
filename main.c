/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:21:35 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/02 11:12:35 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "sys_utils.h"
#include "board.h"
#include "render.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int fd;
	char *file;
	char **array;
	t_board *board;
	t_render *r;

	if (argc != 2)
		quit_properly();
	fd = open(argv[1], O_RDONLY);
	if(!fd)
		quit_properly();
	file = readfile(fd);
	if(!file)
		quit_properly();
	array = ft_strtok(file, '\n');
	board = parse_info(array);

	r = resolve(board);
	print_render(r);
}
