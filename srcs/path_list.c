/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:45:30 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/20 01:06:11 by rvalenti         ###   ########.fr       */
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
	size_t	j;
	size_t	i;
	t_path	*tmp;
	t_path	*prev;

	i = 0;
	len = npath(data);
	if (!(data->path_tab = (t_path **)ft_memalloc(sizeof(t_path*) * len)))
		exit(0);
	tmp = data->global_path;
	while (i < len - 1)
	{
		prev = tmp;
		j = 0;
		while (prev)
		{
			if (prev->room->state == 2)
			{
				tmp->size = j;
				data->path_tab[i] = tmp;
				tmp = prev->next;
				prev->next = NULL;
				break ;
			}
			else if (prev->next->room->state == 1)
			{
				j = 0;
				tmp = prev->next;
			}
			j++;
			if (prev->next)
				prev = prev->next;
		}
		i++;
	}
	check_overlap_path(data, tab_struc_len(data->path_tab));
	merge_ifeq_path(data, tab_struc_len(data->path_tab));
	sort_path_tab(data->path_tab, tab_struc_len(data->path_tab));
}
