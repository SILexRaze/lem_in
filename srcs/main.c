/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/24 12:40:21 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset_connex(t_map *tmp)
{
	while (tmp)
	{
		tmp->weight = 0;
		tmp = tmp->next;
	}
}

int		main(void)
{
	t_data	*data;
	t_map	*tmp;
	t_path	*tmpath;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (0);
	read_stdin(data);
	if (!isvalid_room(data))
		error(-1);
	link_pipe(data);
	tmp = data->map;
	isvalid_map(data);
	printf("%s|", data->start->name);
	set_dimension(data->start,data->start, 0);
	while (tmp)
	{
		printf("%s\tc=%ld\t%ld\n", tmp->name, tmp->connex, tmp->n);
		tmp =tmp->next;
	}
	explore(data->start, data, NULL);
	tmpath = data->global_path;
	while (tmpath)
	{
		printf("%s-", tmpath->room->name);
		tmpath = tmpath->next;
	}
	printf("\n");
	tmpath = data->global_path;
	while (tmpath)
	{
		printf("%s-", tmpath->room->name);
		tmpath = tmpath->next;
	}
	printf("\n");
	pathlist_totab(data);
	ft_print_list(&data->raw_input);
	printf_review(data);
//	pathfinder(data);
//	ant_path(data);
	free_struct(data);
	return (0);
}
