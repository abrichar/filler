/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:33:06 by eliajin           #+#    #+#             */
/*   Updated: 2017/12/12 21:56:45 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h> /////////////////////////////////////////////

typedef struct	s_filler
{
	char		letter_player;
	char		letter_ennemi;
	int			nbr_player;
	int			x_map;
	int			y_map;
	char		**map;
	int			x_token;
	int			y_token;
	char		**token;
	int			x_player;
	int			y_player;
	int			x_ennemi;
	int			y_ennemi;
	int			x_placement;
	int			y_placement;
}				t_filler;
void			parsing_token(char *line, t_filler *f);
void			init_pos_player(t_filler *f);
void			parsing_plateau(char *line, t_filler *f);
int				choose_strat(t_filler *f);
int				check_cond(t_filler *f, int i, int j);
#endif
