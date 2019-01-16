/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:35:33 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/15 19:36:12 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_overlap_path(t_data *data)
{
	int		n;
	int 	i;
	t_path	*tmp;
	t_path	*tmp2;

	i = 0;
	n = tab_struc_len(data->path_tab);
	while (i < n - 1)
	{
		tmp = data->path_tab[i];
		while (tmp)
		{
			tmp2 = data->path_tab[i + 1];
			while (tmp2)
			{
				if (tmp2->room == tmp->room
						&& tmp->room->state == tmp2->room->state
						&& tmp->room->state == 0)
				{
					//supprimer le chemin le plus long
					return (1);
				}
				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

void	merge_ifeq_path(t_data *data)
{
	t_path	*tmp;
	t_path	*tmp2;
	int		i;
	int		n;

	i = 0;
	n = tab_struc_len(data->path_tab);
	while (i < n)
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
					tmp->next = tmp2->next; 
				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
		}
		i++;
	}
}
