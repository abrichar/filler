/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resol.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:18:37 by abrichar          #+#    #+#             */
/*   Updated: 2017/12/11 17:53:36 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_position(t_filler *f, int i, int j)
{
	int binaire;
	int x;
	int y;

	binaire = 0;
	x = 0;
	while (x < f->x_token)
	{
		y = 0;
		while (y < f->y_token)
		{
			if ((f->map[x + i][y + j] == f->letter_player ||
				 f->map[x + i][y + j] == f->letter_player - 32)
				&& f->token[x][y] == '*')
				binaire++;
			if ((f->map[x + i][y + j] == f->letter_ennemi ||
				 f->map[x + i][y + j] == f->letter_ennemi - 32)
				&& f->token[x][y] == '*')
				return (0);
			y++;
		}
		x++;
	}
	return ((binaire == 1) ? 1 : 0);
}

int	check_cond(t_filler *f, int i, int j)
{
	if (i + f->x_token > f->x_map || j + f->y_token > f->y_map)
		return (0);
	else return (check_position(f, i, j));
}
