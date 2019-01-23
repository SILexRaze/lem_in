/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/23 10:53:27 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset_connex(t_map *tmp)
{
	while (tmp)
	{
		tmp->connex = 0;
		tmp->weight = 0;
		tmp = tmp->next;
	}
}

int		main(void)
{
	t_data	*data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (0);
	read_stdin(data);
	if (!isvalid_room(data))
		error(-1);
	link_pipe(data);
	isvalid_map(data);
	explore(data->start, data, NULL);
	if (!check_ifpath(data))
	{
		free_path(data);
		reset_connex(data->map);
		count_connex(data->map, NULL);
		explore_safe_mode(data->start, data);
	}
	if (!check_ifpath(data))
		error(-3);
	pathlist_totab(data);
	ft_print_list(&data->raw_input);
	pathfinder(data);
	ant_path(data);
	free_struct(data);
	return (0);
}
