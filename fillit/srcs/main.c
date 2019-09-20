/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:21:05 by arkim             #+#    #+#             */
/*   Updated: 2019/09/05 19:50:26 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	int			fd;
	t_tet		tet;
	uint16_t	board[MAX_BOARD_SIZE + 3];

	if (ac != 2)
		EXIT(USAGE_ERROR);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		EXIT(ERROR);
	if (!read_file(fd, &tet))
		EXIT(ERROR);
	ft_bzero(board, sizeof(uint16_t) * (MAX_BOARD_SIZE + 3));
	if (!solve_main(&tet, board))
		EXIT(ERROR);
	if (!print_board(&tet))
		EXIT(ERROR);
	close(fd);
	return (0);
}
