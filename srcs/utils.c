/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:23:26 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/11 17:20:53 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_pipesize(t_map **pipe)
{
	size_t	i;

	i = 0;
	while (pipe[i])
		i++;
	return (i);
}

void	ft_free_path(t_data *data)
{
	t_path	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	while (data->path_tab[i])
	{
		while (data->path_tab[i])
		{
			tmp = data->path_tab[i];
			data->path_tab[i] = data->path_tab[i]->next;
			free(tmp);
		}
		data->path_tab[i] = NULL;
		i++;
	}
	free(data->path_tab);
	data->path_tab = NULL;
}

void	ft_free_struct(t_data *data)
{
	ft_free_path(data);
	ft_free_pipe(data);
	ft_free_map(data);
	free(data);
}
