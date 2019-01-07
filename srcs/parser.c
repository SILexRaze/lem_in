/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:03:58 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/07 11:02:37 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_read_stdin(t_data *data)
{
	char	*line;
	char	**tab;
	int		state;

	state = 0;
	if (get_next_line(0, &line) > 0)
	{
		printf("|%s|\n", line);
		data->ant = ft_sizetoi(line);
		ft_strdel(&line);
	}
	while (get_next_line(0, &line) > 0)
	{
		printf("|%s|\n", line);
		tab = ft_strsplit(line, ' ');
		if (ft_tab_len(tab) != 3)
		{
			tab = ft_strsplit(line, '-');
			if (ft_tab_len(tab) == 2)
				ft_pipe_pushback(&data->pipe, tab);
			break;
		}
		ft_map_pushback(&data->map, tab, state);
		ft_strdel(&line);
	}
	while (get_next_line(0, &line) > 0)
	{
		printf("|%s|\n", line);
		tab = ft_strsplit(line, '-');
		if (ft_tab_len(tab) != 2)
			break;
		ft_pipe_pushback(&data->pipe, tab);
		ft_strdel(&line);
	}
}
