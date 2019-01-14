/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/14 15:27:02 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_data	*data;

	if(!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (0);
	printf("%d\n", ft_read_stdin(data));
	if (!ft_isvalid_room(data))
		ft_error(-1);
	ft_link_pipe(data);
	ft_isvalid_map(data);
	ft_explore(data->start, data, NULL);
	ft_pathlist_totab(data);
	printf_review(data);
	ant_path(data);
	//ft_free_struct(data);
	return (0);
}
