/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:53:46 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/20 04:31:34 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	count_connex(t_map *tmp)
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
			if (pipesize(tmp->pipe[i]->pipe) > 1 || tmp->pipe[i]->state == 1)
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

int		check_weight(t_map *tmp)
{
	if (tmp->weight < (size_t)tmp->connex)
		return (0);
	else
		return (1);
}

int		priority(t_map *tmp)
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
		if ((tmp->pipe[i]->weight <= min && tmp->pipe[i]->connex != -1
					&& check_weight(tmp->pipe[i]) == 0))
		{
			min = tmp->pipe[i]->weight;
			j = i;
		}
	}
	return (j);
}

int		check_start(t_map *tmp)
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

int		explore(t_map *tmp, t_data *data, t_map *prev)
{
	size_t	i;
	printf("%s-", tmp->name);
	sleep(5000);
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
