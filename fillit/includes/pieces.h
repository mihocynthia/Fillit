/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:29:45 by arkim             #+#    #+#             */
/*   Updated: 2019/09/05 19:21:37 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECES_H
# define PIECES_H

# include <unistd.h>

const uint64_t		g_pieces_value[19] =
{
	4222124650659840,
	1970342016843776,
	1970333426909184,
	1970329131941888,
	1688862745165824,
	1125929971613696,
	844450699935744,
	844437815033856,
	844433520197632,
	844429225164800,
	562980018192384,
	562962838454272,
	562962838388736,
	562958543552512,
	281505041481728,
	281487861743616,
	281479271874560,
	281487861678080,
	281479271743489
};

const int			g_pieces_height[19] =
{
	1,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	3,
	3,
	2,
	3,
	3,
	3,
	2,
	3,
	3,
	3,
	4
};

const int			g_pieces_width[19] =
{
	4,
	3,
	3,
	3,
	3,
	3,
	3,
	2,
	2,
	2,
	3,
	2,
	2,
	2,
	3,
	2,
	2,
	2,
	1
};

#endif

/*
**	0000000000001111		piece[0]
**	0000000000000000		value	=	4222124650659840
**	0000000000000000		height	=	1
**	0000000000000000		width	=	4
**
**	0000000000000111		piece[1]
**	0000000000000100		value	=	1970342016843776
**	0000000000000000		height	=	2
**	0000000000000000		width	=	3
**
**	0000000000000111		piece[2]
**	0000000000000010		value	=	1970333426909184
**	0000000000000000		height	=	2
**	0000000000000000		width	=	3
**
**	0000000000000111		piece[3]
**	0000000000000001		value	=	1970329131941888
**	0000000000000000		height	=	2
**	0000000000000000		width	=	3
**
**	0000000000000110		piece[4]
**	0000000000000011		value	=	1688862745165824
**	0000000000000000		height	=	2
**	0000000000000000		width	=	3
**
**	0000000000000100		piece[5]
**	0000000000000111		value	=	1125929971613696
**	0000000000000000		height	=	2
**	0000000000000000		width	=	3
**
**	0000000000000011		piece[6]
**	0000000000000110		value	=	844450699935744
**	0000000000000000		height	=	2
**	0000000000000000		width	=	3
**
**	0000000000000011		piece[7]
**	0000000000000011		value	=	844437815033856
**	0000000000000000		height	=	2
**	0000000000000000		width	=	2
**
**	0000000000000011		piece[8]
**	0000000000000010		value	=	844433520197632
**	0000000000000010		height	=	3
**	0000000000000000		width	=	2
**
**	0000000000000011		piece[9]
**	0000000000000001		value	=	844429225164800
**	0000000000000001		height	=	3
**	0000000000000000		width	=	2
**
**	0000000000000010		piece[10]
**	0000000000000111		value	=	562980018192384
**	0000000000000000		height	=	2
**	0000000000000000		width	=	3
**
**	0000000000000010		piece[11]
**	0000000000000011		value	=	562962838454272
**	0000000000000010		height	=	3
**	0000000000000000		width	=	2
**
**	0000000000000010		piece[12]
**	0000000000000011		value	=	562962838388736
**	0000000000000001		height	=	3
**	0000000000000000		width	=	2
**
**	0000000000000010		piece[13]
**	0000000000000010		value	=	562958543552512
**	0000000000000011		height	=	3
**	0000000000000000		width	=	2
**
**	0000000000000001		piece[14]
**	0000000000000111		value	=	281505041481728
**	0000000000000000		height	=	2
**	0000000000000000		width	=	3
**
**	0000000000000001		piece[15]
**	0000000000000011		value	=	281487861743616
**	0000000000000010		height	=	3
**	0000000000000000		width	=	2
**
**	0000000000000001		piece[16]
**	0000000000000001		value	=	281479271874560
**	0000000000000011		height	=	3
**	0000000000000000		width	=	2
**
**	0000000000000001		piece[17]
**	0000000000000011		value	=	281487861678080
**	0000000000000001		height	=	3
**	0000000000000000		width	=	2
**
**	0000000000000001		piece[18]
**	0000000000000001		value	=	281479271743489
**	0000000000000001		height	=	4
**	0000000000000001		width	=	1
*/
