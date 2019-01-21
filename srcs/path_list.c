/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:45:30 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/21 16:08:04 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*path_create_elem(t_map *room, size_t size)
{
	t_path	*new;

	if (!(new = (t_path*)ft_memalloc(sizeof(t_path))))
		exit(0);
	new->room = room;
	new->size = size;
	new->next = NULL;
	new->freenext = NULL;
	return (new);
}

void	path_pushback(t_path **begin_list, t_map *room, size_t size)
{
	t_path	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = path_create_elem(room, size);
		tmp->freenext = tmp->next;
	}
	else
		*begin_list = path_create_elem(room, size);
}

size_t	path_len(t_path **begin_list)
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

size_t	npath(t_data *data)
{
	size_t	i;
	t_path	*tmp;

	tmp = data->global_path;
	i = 0;
	while (tmp)
	{
		if (tmp->room->state == 2)
			i++;
		tmp = tmp->next;
	}
	return (i + 1);
}

void	pathlist_totab(t_data *data)
{
	size_t	len;
	size_t	i;
	size_t	j;
	t_path	*start;
	t_path	*tmp;
	t_path	*prev;

	len = npath(data);
	i = 0;
	start = NULL;
	if (!(data->path_tab = (t_path **)ft_memalloc(sizeof(t_path*) * len)))
		exit(0);
	tmp = data->global_path;
	while (i < len)
	{
		j = 0;
		while (tmp)
		{
			if (tmp->room->state == 1)
				start = tmp;
			if (tmp->room->state == 2)
			{
				start->size = j;
				data->path_tab[i] = start;
				prev = tmp;
				tmp = tmp->next;
				start = tmp;
				prev->next = NULL;
				break; 
			}
			else
				tmp = tmp->next;
			j++;
		}
		i++;
	}
	merge_ifeq_path(data, tab_struc_len(data->path_tab));
	sort_path_tab(data->path_tab, tab_struc_len(data->path_tab));
	check_overlap_path(data, tab_struc_len(data->path_tab));
}
