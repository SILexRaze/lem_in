/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/22 18:09:39 by vifonne          ###   ########.fr       */
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
	link_pipe(data);
	tmp = data->map;
/*	while (tmp)
	{
		printf("%s\t%ld\n",tmp->name,  tmp->connex);
		tmp = tmp->next;
	}*/
	isvalid_map(data);
	set_dimension(data->start, data->start, 1);
	data->start->n = 0;
	tmp = data->map;
	while (tmp)
	{
		printf("|%d|%s|\n", tmp->n, tmp->name);
		tmp = tmp->next;
	}
	explore(data->start, data, NULL);
	check_ifpath(data);
	pathlist_totab(data);
	/*ft_print_list(&data->raw_input);
	pathfinder(data);
	ant_path(data);*/
	printf_review(data);
	free_struct(data);
	return (0);
}
