/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:26:52 by abrichar          #+#    #+#             */
/*   Updated: 2017/12/13 16:13:01 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
//1: bas gauche| 2: haut droit| 3: bas droit|4: haut gauche

int		strat1(t_filler *f)
{
	int i;
	int j;

	ft_putstr_fd("strat1\n", 2);
	i = f->x_map;
	while (i > 0)
	{
		j = 0;
		while (j < f->y_map)
		{
			if (check_cond(f, i , j) == 1)
			{
				f->x_placement = i;
				f->y_placement = j;
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

int		strat2(t_filler *f)
{
	int i;
	int j;

	ft_putstr_fd("strat1\n", 2);
	i = 0;
	while (i < f->x_map)
	{
		j = f->y_map;
		while (j > 0)
		{
			if (check_cond(f, i , j) == 1)
			{
				f->x_placement = i;
				f->y_placement = j;
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

int		strat3(t_filler *f)
{
	int i;
	int j;

	ft_putstr_fd("strat1\n", 2);
	i = f->x_map;
	while (i > 0)
	{
		j = f->y_map;
		while (j > 0)
		{
			if (check_cond(f, i , j) == 1)
			{
				f->x_placement = i;
				f->y_placement = j;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int		strat4(t_filler *f)
{
	int i;
	int j;

	ft_putstr_fd("strat1\n", 2);
	i = 0;
	while (i < f->x_map)
	{
		j = 0;
		while (j < f->y_map)
		{
			if (check_cond(f, i , j) == 1)
			{
				f->x_placement = i;
				f->y_placement = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	choose_strat(t_filler *f)
{
	if (f->x_ennemi < f->x_player)
		if (f->y_ennemi < f->y_player)
			return (strat3(f));
		else return(strat2(f));
	else if (f->y_ennemi < f->y_player)
		return(strat1(f));
	else
		return(strat4(f));
}
