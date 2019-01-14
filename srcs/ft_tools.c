/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:30:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/13 13:34:49 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_sizetoi(char *str)
{
	size_t i;
	size_t dst;

	i = 0;
	dst = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		dst = dst * 10 + str[i] - 48;
		i++;
	}
	return (dst);
}

int		ft_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_freetab(char ***tab)
{
	size_t i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
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
	}
	data->pipe = NULL;
}

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
		free(tmp);
	}
	data->map = NULL;
}
