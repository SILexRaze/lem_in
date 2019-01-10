/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:12:12 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/10 14:50:14 by vifonne          ###   ########.fr       */
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
	data->start = tmp;
	if (data->pipe == NULL)
		return (-15);
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
