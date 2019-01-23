/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:53:46 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/23 23:43:49 by vifonne          ###   ########.fr       */
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

int		priority(t_map *tmp)
{
	size_t	i;
	long	min;
	int		j;

	i = 0;
	while (tmp->pipe[i] < 0)
		i++;
	min = tmp->pipe[i]->weight;
	i = 0;
	j = 0;
	while (tmp->pipe[i])
	{
		if (tmp->pipe[i]->state == 2 && (j = i))
			return (j);
		i++;
	}
	i = 0;
	while (tmp->pipe[i])
	{
		if ((tmp->pipe[i]->weight <= min && tmp->pipe[i]->connex != -1
					&& check_weight(tmp->pipe[i]) == 0))
		{
			min = tmp->pipe[i]->weight;
			j = i;
		}
		i++;
	}
	return (j);
}

int		priority_safe_mode(t_map *tmp)
{
	size_t	i;
	long	min;
	int		j;

	i = 0;
	while (tmp->pipe[i] < 0)
		i++;
	min = tmp->pipe[i]->weight;
	i = 0;
	j = 0;
	while (tmp->pipe[i])
	{
		if (tmp->pipe[i]->state == 2 && (j = i))
			return (j);
		i++;
	}
	i = 0;
	while (tmp->pipe[i])
	{
		if (tmp->pipe[i]->weight <= min && tmp->pipe[i]->connex != -1)
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
	size_t	i;

	i = 0;
	while (tmp->pipe[i])
	{
		if (tmp->pipe[i]->weight < tmp->pipe[i]->connex)
			return (0);
		i++;
	}
	return (1);
}

int		explore(t_map *tmp, t_data *data, t_map *prev)
{
	size_t	i;

	i = priority(tmp);
	tmp->weight++;
	path_pushback(&data->global_path, tmp, 0);
	if (tmp->state == 1 && check_start(tmp) == 1)
		return (1);
	if (tmp->state == 2)
		return (explore(data->start, data, NULL));
	if (tmp->pipe[i] != prev)
		return (explore(tmp->pipe[i], data, tmp));
	return (explore(data->start, data, NULL));
}

int		explore_safe_mode(t_map *tmp, t_data *data)
{
	size_t	i;

	i = priority_safe_mode(tmp);
	tmp->weight++;
	path_pushback(&data->global_path, tmp, 0);
	if (tmp->state == 1 && check_start(tmp) == 1)
		return (1);
	if (tmp->state == 2)
		return (1);
	return (explore_safe_mode(tmp->pipe[i], data));
}
