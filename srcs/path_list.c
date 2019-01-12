/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:45:30 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/12 15:33:56 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_path_create_elem(t_map *room, size_t size)
{
	t_path	*new;

	if (!(new = (t_path*)ft_memalloc(sizeof(t_path))))
		exit(0);
	new->room = room;
	new->size = size;
	new->next = NULL;
	return (new);
}

void	ft_path_pushback(t_path **begin_list, t_map *room, size_t size)
{
	t_path	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_path_create_elem(room, size);
	}
	else
		*begin_list = ft_path_create_elem(room, size);
}

size_t	ft_path_len(t_path **begin_list)
{
	t_path	*tmp;
	size_t	i;

	i = 0;
	tmp = *begin_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

size_t	ft_npath(t_data *data)
{
	size_t	i;
	t_path	*tmp;

	tmp = data->global_path;
	i = 0;
	while (tmp)
	{
		if (tmp->room == data->start)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_pathlist_totab(t_data *data)
{
	size_t	len;
	size_t	j;
	size_t	i;
	t_path	*tmp;
	t_path	*prev;

	i = 0;
	len = ft_npath(data);
	if (!(data->path_tab = (t_path **)ft_memalloc(sizeof(t_path*) * len)))
		exit(0);
	tmp = data->global_path;
	while (i < len - 1)
	{
		data->path_tab[i] = tmp;
		prev = tmp;
		j = 0;
		while (prev)
		{
			if (prev->room->state == 2)
			{
				tmp->size = j;
				tmp = prev->next;
				prev->next = NULL;
				break ;
			}
			j++;
			prev = prev->next;
		}
		i++;
	}
	sort_path_tab(data->path_tab, len - 1);
}
