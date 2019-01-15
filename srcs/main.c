/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/15 19:36:11 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_data	*data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (0);
	ft_read_stdin(data);
	if (!ft_isvalid_room(data))
		ft_error(-1);
	ft_link_pipe(data);
	ft_isvalid_map(data);
	ft_explore(data->start, data, NULL);
	ft_pathlist_totab(data);
	printf_review(data);
	ft_print_list(&data->raw_input);
	check_overlap_path(data);
	merge_ifeq_path(data);
	ant_path(data);
	ft_free_struct(data);
	return (0);
}
