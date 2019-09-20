/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:48:12 by arkim             #+#    #+#             */
/*   Updated: 2019/09/05 21:17:59 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define BUFF_SIZE 20
# define CHECKBIT 281479271743489

/*
**	CHECKBIT = 281479271743489
**	0000000000000001 \
**	0000000000000001 \
**	0000000000000001 \
**	0000000000000001
*/

# define EXIT(error_msg)	ft_puterror(error_msg)
# define USAGE_ERROR		"usage: fillit input_file"
# define ERROR				"error"

# define MAX_N_TETS 26
# define MAX_BOARD_SIZE 16
# define TET(idx)		tet->pieces[idx]

typedef	struct	s_tetrimino_info
{
	char		idx;
	uint64_t	piece;
	int			height;
	int			width;
	uint64_t	solved_piece;
	int			row_num;
}				t_info;

typedef struct	s_tetrimino
{
	int			n_tets;
	int			board_size;
	int			solve_flag;
	t_info		pieces[MAX_N_TETS];
}				t_tet;

/*
**			input.c
*/

int				read_file(int fd, t_tet *tet);
void			align_piece(uint64_t *piece);
uint64_t		validity_check(char *buff);
int				assign_piece_info(uint64_t piece, t_tet *tet, int idx);

/*
**			solve.c
*/

int				solve_main(t_tet *tet, uint16_t *board);
int				move_piece(uint64_t *piece, t_info p, int b_size, int *row_num);
int				solving(t_tet *tet, int idx, int b_size, uint16_t *board);

/*
**			print.c
*/

int				print_board(t_tet *tet);
char			*set_board(int board_size);

/*
**			utils.c
*/

int				count_one(uint64_t n);
int				get_min_board_size(t_tet *tet);

#endif
