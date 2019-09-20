/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:05:35 by arkim             #+#    #+#             */
/*   Updated: 2019/09/05 19:47:43 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve_main(t_tet *tet, uint16_t *board)
{
	int			board_size;

	board_size = get_min_board_size(tet);
	tet->solve_flag = 0;
	while (!(solving(tet, 0, board_size, board)))
		board_size++;
	tet->board_size = board_size;
	return (1);
}

int			move_piece(uint64_t *piece, t_info p, int b_size, int *row_num)
{
	if ((*piece & CHECKBIT) == 0)
		*piece >>= 1;
	else if (*row_num < (b_size - p.height))
	{
		*piece <<= (b_size - p.width);
		(*row_num)++;
	}
	else
		return (-1);
	return (*row_num);
}

int			solving(t_tet *tet, int idx, int b_size, uint16_t *board)
{
	int			b_row;
	uint64_t	tmp;

	if (tet->solve_flag == ((1 << tet->n_tets) - 1))
		return (1);
	tmp = (TET(idx).piece << (b_size - TET(idx).width));
	b_row = 0;
	while (1)
	{
		if (!(*(uint64_t *)(board - b_row) & tmp))
		{
			*(uint64_t *)(board - b_row) ^= tmp;
			TET(idx).solved_piece = tmp;
			TET(idx).row_num = b_row;
			tet->solve_flag |= (1 << idx);
			if (solving(tet, idx + 1, b_size, board) == 1)
				return (1);
			TET(idx).solved_piece = 0;
			tet->solve_flag &= ~(1 << idx);
			*(uint64_t *)(board - b_row) ^= tmp;
		}
		if ((move_piece(&tmp, TET(idx), b_size, &b_row)) == -1)
			break ;
	}
	return (0);
}
