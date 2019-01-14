/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:44:01 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/14 17:02:45 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ant_move(t_path *path,t_path *prev , t_data *data)
{
	if (path->room->state == 1 && path->room->nbant && path->next->room->nbant == 0)
	{
		path->room->nbant--;
		path->room->nameant = data->ant - path->room->nbant;
		path->next->room->nameant = path->room->nameant;
		path->next->room->nbant++;
		print_ant(path);
	}
	else if (path->next && path->room->state != 1 && path->room->nbant == 1
			&& (path->next->room->nbant == 0 || path->next->room->state == 2))
	{
		path->next->room->nameant = path->room->nameant;
		path->room->nameant = 0;
		path->next->room->nbant++;
		path->room->nbant--;
		print_ant(path);
		if (prev->room->nbant)
			return (ant_move(prev, NULL, data));
	}
	else if (path->next)
		return (ant_move(path->next, path, data));
	return (0);
}

void	print_ant(t_path *path)
{
	write(1, "L", 1);
	ft_putnbr(path->next->room->nameant);
	write(1, "-", 1);
	ft_putstr(path->next->room->name);
	write(1, " ", 1);
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
		ant_move(data->path_tab[0], data->path_tab[0], data);
		write(1, "\n", 1);
	}
	return (0);
}
