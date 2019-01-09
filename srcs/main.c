/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:08 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/09 15:36:32 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_data	*data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (0);
	ft_read_stdin(data);
	ft_link_pipe(data);
	if (ft_isvalid_map(data) < 0)
		printf("FT_ISVALID_MAP=%d\n", ft_isvalid_map(data));
	printf_review(data);
	ft_free_struct(data);
	return (0);
}

void	ft_free_struct(t_data *data)
{
	t_pipe	*tmp;
	t_map	*tmpmap;

	tmpmap = NULL;
	tmp = NULL;
	while (data->pipe)
	{
		tmp = data->pipe;
		data->pipe = data->pipe->next;
		ft_strdel(&tmp->arg1);
		ft_strdel(&tmp->arg2);
		free(tmp);
	}
	data->pipe = NULL;
	while (data->map)
	{
		tmpmap = data->map;
		data->map = data->map->next;
		ft_strdel(&tmpmap->name);
		free(tmpmap->pipe);
		free(tmpmap);
	}
	data->map = NULL;
	free(data);
}
