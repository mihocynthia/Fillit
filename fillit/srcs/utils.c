/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 00:39:06 by arkim             #+#    #+#             */
/*   Updated: 2019/09/05 19:46:57 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_one(uint64_t n)
{
	uint64_t	tmp;
	int			count;

	count = 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp &= tmp - 1;
		count++;
	}
	return (count);
}

int			get_min_board_size(t_tet *tet)
{
	if (tet->n_tets == 1 && TET(0).piece == 844437815033856)
		return (2);
	if (tet->n_tets <= 2 && (TET(0).height != 4 && TET(0).width != 4
		&& TET(1).height != 4 && TET(1).width != 4))
		return (3);
	if (tet->n_tets <= 4)
		return (4);
	if (tet->n_tets <= 6)
		return (5);
	if (tet->n_tets <= 9)
		return (6);
	if (tet->n_tets <= 12)
		return (7);
	if (tet->n_tets <= 16)
		return (8);
	if (tet->n_tets <= 20)
		return (9);
	if (tet->n_tets <= 25)
		return (10);
	if (tet->n_tets == 26)
		return (11);
	return (-1);
}
