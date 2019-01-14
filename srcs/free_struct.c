/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:25:37 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/14 17:04:54 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_map(t_data *data)
{
	t_map	*tmp;

	tmp = NULL;
	while (data->map)
	{
		tmp = data->map;
		data->map = data->map->next;
		ft_strdel(&tmp->name);
		free(tmp->pipe);
		tmp->pipe = NULL;
		free(tmp);
		tmp = NULL;
	}
	data->map = NULL;
}

void	ft_free_path(t_data *data)
{
	t_path	*tmp;

	tmp = NULL;
	while (data->global_path)
	{
		tmp = data->global_path;
		data->global_path = data->global_path->next;
		free(tmp);
		tmp = NULL;
	}
	data->global_path = NULL;
}

void	ft_free_pipe(t_data *data)
{
	t_pipe	*tmp;

	tmp = NULL;
	while (data->pipe)
	{
		tmp = data->pipe;
		data->pipe = data->pipe->next;
		ft_strdel(&tmp->arg1);
		ft_strdel(&tmp->arg2);
		free(tmp);
		tmp = NULL;
	}
	data->pipe = NULL;
}

void	ft_free_struct(t_data *data)
{
	ft_free_map(data);
	ft_free_path(data);
	ft_free_pipe(data);
	ft_list_del(&data->raw_input);
	free(data->path_tab);
	data->path_tab = NULL;
	free(data);
	data = NULL;
}
