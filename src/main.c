/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:31:48 by eliajin           #+#    #+#             */
/*   Updated: 2017/12/13 16:14:04 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_filler	*f;
	char		*line;

	get_next_line(0, &line);
	f = (t_filler *)malloc(sizeof(t_filler));
	f->nbr_player = ft_atoi(&line[10]);
	f->letter_player = (f->nbr_player == 1) ? 'O' : 'X';
	f->letter_ennemi = (f->letter_player == 'o') ? 'x' : 'o';
	while (1)
	{
		get_next_line(0, &line);
		parsing_plateau(line, f);
		get_next_line(0, &line);
		parsing_token(line, f);
		if (choose_strat(f) == 0)
		{
			ft_putstr("0 0\n");
			break ;
		}
		ft_printf("%d %d\n", f->x_placement, f->y_placement);
	}
	free(f);
	free(line);
	return (0);
}
