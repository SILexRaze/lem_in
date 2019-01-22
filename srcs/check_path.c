/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:35:33 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/21 16:08:47 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_overlap_path(t_data *data, int n)
{
	int		i;
	t_path	*tmp;
	t_path	*tmp2;

	i = -1;
	while (++i < n - 1)
	{
		tmp = data->path_tab[i]->next;
		while (tmp && i < n - 1)
		{
			tmp2 = data->path_tab[i + 1]->next;
			while (tmp2 && i < n - 1)
			{
				if (ft_strequ(tmp->room->name, tmp2->room->name) == 1
						&& tmp->room->state == 0 && tmp2->room->state == 0)
				{
					delete_path(data, i + 1);
					n = tab_struc_len(data->path_tab);
					break ;
				}
				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
		}
	}
}

void	merge_ifeq_path(t_data *data, int n)
{
	t_path	*tmp;
	t_path	*tmp2;
	int		i;

	i = -1;
	while (++i < n)
	{
		tmp = data->path_tab[i];
		while (tmp)
		{
			tmp2 = tmp->next;
			while (tmp2)
			{
				if (tmp2->room == tmp->room
						&& tmp->room->state == tmp2->room->state
						&& tmp->room->state == 0)
				{
					tmp->next = tmp2->next;
					data->path_tab[i]->size = path_len(&data->path_tab[i]);
				}
				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
		}
	}
}

void	delete_path(t_data *data, int index)
{
	t_path	**tab;
	int		n;
	int		j;
	int		i;

	j = 0;
	i = 0;
	n = tab_struc_len(data->path_tab);
	if (!(tab = (t_path **)ft_memalloc(sizeof(t_path *) * (n))))
		exit(0);
	while (j < n)
	{
		if (j != index)
		{
			tab[i] = data->path_tab[j];
			i++;
		}
		j++;
	}
	data->path_tab = tab;
}

void	check_ifpath(t_data *data)
{
	t_path	*tmp;
	int		end;
	int		start;

	start = 0;
	end = 0;
	tmp = data->global_path;
	while (tmp)
	{
		if (tmp->room->state == 1)
			start++;
		else if (tmp->room->state == 2)
			end++;
		tmp = tmp->next;
	}
	if (start == 0 || end == 0)
		error(-3);
}
