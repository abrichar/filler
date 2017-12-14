/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resol.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:18:37 by abrichar          #+#    #+#             */
/*   Updated: 2017/12/14 17:10:58 by abrichar         ###   ########.fr       */
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
			if (f->token[x][y] == '*')
			{
				if ((f->map[x + i][y + j] == f->letter_player ||
					 f->map[x + i][y + j] == f->letter_player - 32))
					binaire++;
				if ((f->map[x + i][y + j] == f->letter_ennemi ||
					 f->map[x + i][y + j] == f->letter_ennemi - 32))
					return (0);
			}
				y++;
		}
		x++;
	}
	return ((binaire == 1) ? 1 : 0);
}

static int			check_in(t_filler *f, int i, int j)
{
	int x;
	int y;

	x = 0;
	while (x < f->x_token)
	{
		y = 0;
		while (y < f->y_token)
		{
			if (f->token[x][y] == '*')
				if (x + i >= f->x_map || y + j >= f->y_map)
					return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int			check_cond(t_filler *f, int i, int j)
{
	if ((check_in(f, i, j) == 0))
		return (0);
	else return (check_position(f, i, j));
}
