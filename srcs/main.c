/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/10 11:53:52 by vifonne          ###   ########.fr       */
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
	printf_review(data);
	ft_free_pipe(data);
	ft_free_map(data);
	free(data);
	data = NULL;
	return (0);
}
