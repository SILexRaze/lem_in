/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:03:58 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/14 17:04:41 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_read_stdin(t_data *data)
{
	char	*line;
	int		trig;

	trig = 0;
	line = NULL;
	if (!ft_isant(line, data))
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_iscomment(line))
		{
			if (trig == 0 && ft_isroom(line, data) == 1)
				ft_list_pushback(&data->raw_input, ft_strdup(line), 0);
			else if (ft_isinst(line) > 0)
				ft_list_pushback(&data->raw_input, ft_strdup(line), 0);
			else
				trig = 1;
			if (trig == 1 && ft_ispipe(line, data) == 1 && ft_isstate(data) == 0)
				ft_list_pushback(&data->raw_input, ft_strdup(line), 0);
			else if (trig == 1)
				return (-1);
		}
		else if (ft_isstate(data) != 0)
			return (-1);
		ft_strdel(&line);
	}
	return (1);
}

int		ft_isant(char *str, t_data *data)
{
	if (get_next_line(0, &str) > 0)
	{
		if (!ft_strisdigit(str))
			return (0);
		data->ant = ft_sizetoi(str);
		ft_list_pushback(&data->raw_input, ft_strdup(str), 0);
		ft_strdel(&str);
		return (1);
	}
	return (0);
}

int		ft_isroom(char *str, t_data *data)
{
	char	**tab;

	tab = ft_strsplit(str, 32);
	if (ft_tab_len(tab) != 3 || tab[0][0] == 'L' || !ft_strisdigit(tab[1])
			|| !ft_strisdigit(tab[2]) || ft_strchr(str, '-'))
	{
		ft_freetab(&tab);
		return (0);
	}
	if (ft_isstate(data) != 0)
		ft_map_pushback(&data->map, tab, ft_isstate(data));
	else
		ft_map_pushback(&data->map, tab, 0);
	ft_freetab(&tab);
	return (1);
}

int		ft_ispipe(char *str, t_data *data)
{
	char	**tab;

	tab = ft_strsplit(str, '-');
	if (ft_tab_len(tab) != 2 || ft_isminus(str) < 0
			|| ft_strequ(tab[0], tab[1]) == 1)
	{
		ft_freetab(&tab);
		return (0);
	}
	ft_pipe_pushback(&data->pipe, tab);
	ft_freetab(&tab);
	return (1);
}
