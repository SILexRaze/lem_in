/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:53:46 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/14 17:45:35 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_count_connex(t_map *tmp)
{
	size_t	j;
	size_t	i;

	while (tmp)
	{
		i = 0;
		j = 0;
		while (i < tmp->n)
		{
			if (tmp->pipe[i]->state == 2)
			{
				j = 2;
				break ;
			}
			if (ft_pipesize(tmp->pipe[i]->pipe) > 1 || tmp->pipe[i]->state == 1)
				j++;
			i++;
		}
		if (tmp->state != 0)
			tmp->connex = j;
		else
			tmp->connex = j - 1;
		tmp = tmp->next;
	}
}

int		ft_check_weight(t_map *tmp)
{
	if (tmp->weight < (size_t)tmp->connex)
		return (0);
	else
		return (1);
}

int		ft_priority(t_map *tmp)
{
	size_t	i;
	size_t	min;
	int		j;

	min = tmp->pipe[0]->weight;
	i = 0;
	j = 0;
	while (++i < tmp->n)
	{
		if (tmp->pipe[i]->state == 2 && (j = i))
			return (j);
	}
	i = -1;
	while (++i < tmp->n)
	{
		if ((tmp->pipe[i]->weight <= min && tmp->pipe[i]->connex != 0
					&& ft_check_weight(tmp->pipe[i]) == 0))
		{
			min = tmp->pipe[i]->weight;
			j = i;
		}
	}
	return (j);
}

int		ft_check_start(t_map *tmp)
{
	size_t	i;

	i = 0;
	while (i < tmp->n)
	{
		if (tmp->pipe[i]->weight < (size_t)tmp->pipe[i]->connex)
			return (0);
		i++;
	}
	return (1);
}

int		ft_explore(t_map *tmp, t_data *data, t_map *prev)
{
	size_t	i;

	i = ft_priority(tmp);
	tmp->weight++;
	ft_path_pushback(&data->global_path, tmp, 0);
	if (tmp->state == 1 && ft_check_start(tmp) == 1)
		return (1);
	if (tmp->state == 2)
		return (ft_explore(data->start, data, NULL));
	if (tmp->pipe[i] != prev)
		return (ft_explore(tmp->pipe[i], data, tmp));
	return (ft_explore(data->start, data, NULL));
}
