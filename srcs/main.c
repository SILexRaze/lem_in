/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/13 13:11:42 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_data	*data;
	int		ret;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (0);
	ft_read_stdin(data);
	ft_link_pipe(data);
	if ((ret = ft_isvalid_map(data)) < 0)
		ft_error(ret);
	ft_explore(data->start, data, NULL);
	ft_pathlist_totab(data);
	printf_review(data);
//	ft_free_struct(data);
	data = NULL;
	return (0);
}
