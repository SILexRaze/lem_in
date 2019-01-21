/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/21 16:18:54 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_data	*data;
	t_map	*tmp;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (0);
	read_stdin(data);
	if (!isvalid_room(data))
		error(-1);
	//	printf_review(data);
	link_pipe(data);
	tmp = data->map;
	while (tmp)
	{
		if (data->map->connex == 0)
		{
			//printf("%s\t%zu\n",data->map->name,  data->map->connex);
			data->map->connex = -1;
		}
		tmp = tmp->next;
	}
	isvalid_map(data);
	explore(data->start, data, NULL);
	check_ifpath(data);
	pathlist_totab(data);
	ft_print_list(&data->raw_input);
	pathfinder(data);
	ant_path(data);
	free_struct(data);
	return (0);
}
