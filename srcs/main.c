/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/22 09:36:45 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	while (tmp)
	{
		printf("%s\t%ld\n",tmp->name,  tmp->connex);
		tmp = tmp->next;
	}
	isvalid_map(data);
	explore(data->start, data, NULL);
	tmpath = data->global_path;
	printf("\n\n");
	while (tmpath)
	{
		printf("%s-", tmpath->room->name);
		tmpath = tmpath->next;
	}
	printf("\n\n");
	check_ifpath(data);
	pathlist_totab(data);
	printf_review(data);
	ft_print_list(&data->raw_input);
	pathfinder(data);
	ant_path(data);
	free_struct(data);
	return (0);
}
