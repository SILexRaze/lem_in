/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:12:12 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/13 18:12:30 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isvalid_map(t_data *data)
{
	t_map	*tmp;

	tmp = data->map;
	if (!ft_isvalid_room(data) || !ft_isvalid_pipe(data))
		ft_error(-1);
	if ((data->errcode = ft_count_state(data)) < 0)
		ft_error(data->errcode);
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
		ft_error(-15);
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

int		ft_isvalid_room(t_data *data)
{
	t_map	*tmp;
	t_map	*tmp2;

	tmp = data->map;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strequ(tmp2->name, tmp->name) == 1 || (tmp->x == tmp2->x
						&& tmp->y == tmp2->y))
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		ft_isvalid_pipe(t_data *data)
{
	t_pipe	*tmpipe;
	t_pipe	*tmpipe2;

	tmpipe = data->pipe;
	while (tmpipe)
	{
		tmpipe2 = tmpipe->next;
		while (tmpipe2)
		{
			if (ft_strequ(tmpipe->arg1, tmpipe2->arg1) == 1
				&& ft_strequ(tmpipe->arg2, tmpipe2->arg2) == 1)
				return (0);
			if (ft_strequ(tmpipe->arg2, tmpipe2->arg1) == 1
				&& ft_strequ(tmpipe->arg1, tmpipe2->arg2) == 1)
				return (0);
			tmpipe2 = tmpipe2->next;
		}
		tmpipe = tmpipe->next;
	}
	return (1);
}
