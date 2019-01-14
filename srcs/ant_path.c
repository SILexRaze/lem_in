/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:44:01 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/14 14:56:24 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
 ** fontion recursive de deplacement des fourmis
 ** condition d'arret: quand toutes les foumis sont passer de start a end
 ** check si la room next est vide, si oui faire avancer la formis sinon faire avancer la fourmis de la room next ect
 */

int		ant_move(t_path *path)
{
	if (path->next
			&& (path->next->room->nbant == 0 || path->next->room->state != 0))
	{
		path->next->room->nameant = path->room->nameant;
		path->room->nameant = 0;
		path->next->room->nbant++;
		path->room->nbant--;
		write(1, "L", 1);
		ft_putnbr(path->next->room->nameant);
		write(1, "-", 1);
		ft_putstr(path->next->room->name);
		write(1, " ", 1);
	}
	if (path->next)
		return (ant_move(path->next));
	else
		return (0);
}

int		check_ant(t_path *path)
{
	t_path *tmp;

	tmp = path;
	while (tmp)
	{
		if (tmp->room->nbant != 0 && tmp->room->state != 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ant_path(t_data *data)
{
	while (check_ant(data->path_tab[0]))
	{
		ant_move(data->path_tab[0]);
		write(1, "\n", 1);
	}
	return (0);
}
