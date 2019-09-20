/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:33:23 by arkim             #+#    #+#             */
/*   Updated: 2019/09/05 19:47:33 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "pieces.h"

int				read_file(int fd, t_tet *tet)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static int	idx = 0;

	if (fd < 0 || (ret = read(fd, buff, BUFF_SIZE)) != 20 || idx > 26)
		return (0);
	buff[ret] = '\0';
	if (!(assign_piece_info(validity_check(buff), tet, idx)))
		return (0);
	if (!(ret = read(fd, buff, 1)))
	{
		tet->n_tets = idx + 1;
		return (1);
	}
	if (buff[0] == '\n')
	{
		idx++;
		return (read_file(fd, tet));
	}
	else
		return (0);
}

void			align_piece(uint64_t *piece)
{
	while ((*piece & CHECKBIT) == 0)
		*piece >>= 1;
	while ((*piece >> 48) == 0)
		*piece <<= 16;
}

uint64_t		validity_check(char *buff)
{
	int			i;
	uint64_t	piece;

	i = 0;
	piece = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
		{
			if (buff[i] != '\n')
				return (0);
		}
		else if (buff[i] == '#')
			piece |= (1LL << (16 * (3 - (i / 5)) + 3 - (i % 5)));
		else if (buff[i] == '.')
			;
		else
			return (0);
		i++;
	}
	if (count_one(piece) != 4)
		return (0);
	align_piece(&piece);
	return (piece);
}

int				assign_piece_info(uint64_t piece, t_tet *tet, int idx)
{
	int			i;

	i = 0;
	while (i < 19)
	{
		if (piece == g_pieces_value[i])
		{
			TET(idx).piece = g_pieces_value[i];
			TET(idx).height = g_pieces_height[i];
			TET(idx).width = g_pieces_width[i];
			break ;
		}
		i++;
	}
	if (i == 19)
		return (0);
	TET(idx).idx = idx;
	return (1);
}
