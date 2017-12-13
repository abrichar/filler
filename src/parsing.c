/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:55:33 by eliajin           #+#    #+#             */
/*   Updated: 2017/12/12 21:57:15 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parsing_token(char *line, t_filler *f)
{
	int i;

	i = 6;
	f->x_token = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	f->y_token = ft_atoi(&line[i]);
	i = -1;
	f->token = (char**)malloc(sizeof(char*) * (f->x_token *
			f->y_token + f->x_token));
	while (++i < f->x_token)
	{
		get_next_line(0, &line);
		f->token[i] = ft_strdup(line);
	}
}

void	init_pos_player(t_filler *f)
{
	int i;
	int j;

	i = 0;
	f->x_placement = 0;
	f->y_placement = 0;
	while (i < f->x_map)
	{
		j = 0;
		while (j < f->y_map)
		{
			if (f->map[i][j] == f->letter_player)
			{
				f->x_player = i;
				f->y_player = j;
			}
			else if (f->map[i][j] == f->letter_ennemi)
			{
				f->x_ennemi = i;
				f->y_ennemi = j;
			}
			j++;
		}
		i++;
	}
}

void	parsing_plateau(char *line, t_filler *f)
{
	int i;

	i = 8;
	f->x_map = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	f->y_map = ft_atoi(&line[i]);
	get_next_line(0, &line);
	i = -1;
	f->map = (char**)malloc(sizeof(char*) * (f->y_map * f->x_map + f->x_map + f->y_map));
	while (++i < f->x_map)
	{
		get_next_line(0, &line);
		f->map[i] = ft_strdup(line + 4);
	}
	init_pos_player(f);
}

