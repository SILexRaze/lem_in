/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:03:58 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/13 14:47:59 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_read_stdin(t_data *data)
{
	char	*line;
	t_map	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		data->ant = ft_sizetoi(line);
		ft_strdel(&line);
	}
	if ((data->errcode = ft_parse_room(data)) < 1)
	{
		printf("%d\n", data->errcode);
		return ;
	}
	if ((data->errcode = ft_parse_pipe(data)) < 1)
		return ;
	tmp = data->map;
	while (tmp)
	{
		if (tmp->state == 1)
			tmp->nbant = data->ant;
		tmp = tmp->next;
	}
}

int		ft_parse_room(t_data *data)
{
	char	*line;
	char	**tab;
	int		state;
	int		ret;

	state = 0;
	ret = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_state(&line, &state);
		if (!ft_skip_comment(&line))
			return (0);
		tab = ft_strsplit(line, ' ');
		if (ft_tab_len(tab) != 3)
		{
			ft_freetab(&tab);
			tab = ft_strsplit(line, '-');
			if (ft_tab_len(tab) == 2 && (ret = ft_ispipe(line, data, tab)) == 1
					&& state == 0)
			{	
				ft_putendl(line);
				ft_pipe_pushback(&data->pipe, tab);
				ft_freetab(&tab);
				return (1);
			}
			else
			{
				if (ret < 1)
					return (ret);
				else if (state != 0)
					return (-13);
			}
		}
		if ((ret = ft_isroom(data, tab)) <= 0)
			return (ret);
		ft_putendl(line);
		ft_map_pushback(&data->map, tab, state);
		ft_strdel(&line);
		ft_freetab(&tab);
	}
	return (1);
}

int		ft_parse_pipe(t_data *data)
{
	char	*line;
	char	**tab;
	int		ret;

	ret = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_skip_comment(&line))
			return (0);
		tab = ft_strsplit(line, '-');
		if (ft_tab_len(tab) != 2 || (ret = ft_ispipe(line, data, tab)) < 0)
		{
			ft_freetab(&tab);
			return (ret);
		}
		ft_putendl(line);
		ft_pipe_pushback(&data->pipe, tab);
		ft_strdel(&line);
		ft_freetab(&tab);
	}
	return (1);
}

int		ft_skip_comment(char **line)
{
	while (line[0][0] == '#' && line[0][1] != '#')
	{
		ft_strdel(line);
		if (get_next_line(0, line) <= 0)
			return (0);
	}
	return (1);
}

void	ft_state(char **line, int *state)
{
	*state = 0;
	if (line[0][0] == '#' && line[0][1] == '#')
	{
		if (ft_strequ(*line, "##start"))
			*state = 1;
		else if (ft_strequ(*line, "##end"))
			*state = 2;
		ft_putendl(*line);
		ft_strdel(line);
		get_next_line(0, line);
	}
}
