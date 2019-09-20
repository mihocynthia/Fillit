/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 23:09:50 by arkim             #+#    #+#             */
/*   Updated: 2019/09/05 19:43:49 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			print_board(t_tet *tet)
{
	char	*res;
	int		b_size;
	int		i;
	int		j;
	int		b_row;

	b_size = tet->board_size;
	res = set_board(b_size);
	i = -1;
	while (++i < tet->n_tets)
	{
		j = 0;
		b_row = TET(i).row_num;
		while (j < 64)
		{
			if ((j % 16 < b_size) \
				&& ((TET(i).solved_piece & (1LL << j)) == (1LL << j)))
				res[(b_row + (4 - (j / 16) - 1)) * (b_size + 1) \
					+ (b_size - (j % 16) - 1)] = (TET(i).idx + 'A');
			j++;
		}
	}
	ft_putstr(res);
	free(res);
	return (1);
}

char		*set_board(int board_size)
{
	char	*res;
	int		i;

	res = ft_strnew(board_size * (board_size + 1));
	ft_memset(res, '.', board_size * (board_size + 1));
	i = 0;
	while (i < board_size * (board_size + 1))
	{
		if ((i % (board_size + 1)) == board_size)
			res[i] = '\n';
		i++;
	}
	return (res);
}
