/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:53:46 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/22 00:24:32 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_weight(t_map *tmp)
{
	if (tmp->weight < tmp->connex)
		return (0);
	else
		return (1);
}

int		priority(t_map *tmp, t_map *prev)
{
	size_t	i;
	long	min;
	int		j;

	i = 0;
	while (tmp->pipe[i] && tmp->pipe[i]->connex < 0)
		i++;
	if (!tmp->pipe[i])
		return (-1);
	min = tmp->pipe[i]->weight;
	i = 1;
	j = 0;
//	while (i < tmp->n)
//	{
//		if (tmp->pipe[i]->state == 2 && (j = i))
//			return (j);
//		i++;
//	}
	i = 0;
	while (i < tmp->n)
	{
		if ((tmp->pipe[i]->weight <= min && tmp->pipe[i]->connex != -1 && tmp->pipe[i] != prev))
		{
			min = tmp->pipe[i]->weight;
			j = i;
		}
		i++;
	}
	return (j);
}

int		check_start(t_map *tmp)
{
	t_map	*tmap;

	tmap = tmp;
	while (tmap)
	{
//		printf("|%s\tweight=%ld|", tmap->name, tmap->weight);
		if (tmap->weight == 0 && tmap->connex != -1)
			return (0);
		tmap = tmap->next;
	}
	return (1);
}

int		explore(t_map *tmp, t_data *data, t_map *prev)
{
	int	i;

	i = priority(tmp, prev);
	tmp->weight++;
	if (i == -1)
		return (explore(data->start, data, NULL));
//	if (tmp->state != 1)
//		printf("(%s|%ld)->", tmp->name, tmp->connex);
//	else
//		printf("\n(%s|%ld)->", tmp->name, tmp->connex);
	path_pushback(&data->global_path, tmp, 0);
	if (tmp->state == 1 && check_start(tmp) == 1)
		return (1);
	if (tmp->state == 2)
		return (explore(data->start, data, NULL));
	if (tmp->pipe[i] != prev)
		return (explore(tmp->pipe[i], data, tmp));
	return (explore(data->start, data, NULL));
}
