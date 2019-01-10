/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:12:12 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/10 11:52:23 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isvalid_map(t_data *data)
{
	int		ret;
	t_map	*tmp;

	ret = 0;
	tmp = data->map;
	if ((ret = ft_count_state(data)) < 0)
		return (ret);
	while (tmp)
	{
		if (tmp->state == 1)
		{
			tmp->weight = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (data->pipe == NULL)
		return (-15);
/*	if (!ft_check_connection(tmp, tmp))
		return (-14);*/
	return (1);
}

int		ft_count_state(t_data *data)
{
	t_map	*tmp;
	int		start;
	int		end;

	start = 0;
	end = 0;
	tmp = data->map;
	while (tmp)
	{
		if (tmp->state == 1)
			start++;
		else if (tmp->state == 2)
			end++;
		tmp = tmp->next;
	}
	if (start != 1 || start != 1)
		return (-13);
	return (1);
}

int		ft_check_connection(t_map *tmp, t_map *prev)
{
	int i;

	i = 0;
	printf("|%s|\n", tmp->name);
	/*if (tmp->state != 2 && ft_tab_struct_len(tmp->pipe) == 1)
		return (0);
	else if (tmp->state == 2)
		return(1);*/
	while (tmp->pipe[i] && tmp->state != 2)
	{
		if (tmp->pipe[i] != prev && tmp->pipe[i]->weight != 1)
		{
			tmp->weight = 1;
			ft_check_connection(tmp->pipe[i], tmp);
		}
		//printf("/%d/\n\n", i);
		i++;
	}
	if (tmp->state != 2 && ft_tab_struct_len(tmp->pipe) == 1)
		return (0);
	else if (tmp->state == 2)
		return (1);
	else
		return (0);
}

int		ft_tab_struct_len(t_map	**pipe)
{
	size_t	i;

	i = 0;
	while (pipe[i])
		i++;
	return (i);
}
