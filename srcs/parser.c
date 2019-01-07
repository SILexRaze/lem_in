/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:03:58 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/07 13:49:11 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_read_stdin(t_data *data)
{
	char	*line;
	t_map	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		printf("|%s|\n", line);
		data->ant = ft_sizetoi(line);
		ft_strdel(&line);
	}
	ft_parse_map(data);
	tmp = data->map;
	while (tmp)
	{
		if (tmp->state == 1)
			tmp->nbant = data->ant;
		tmp = tmp->next;
	}
}

void	ft_parse_map(t_data *data)
{
	char	*line;
	char	**tab;
	int		state;

	state = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_state(&line, &state);
		if(!ft_comment(&line))
			break ;
		printf("|%s|\n", line);
		tab = ft_strsplit(line, ' ');
		if (ft_tab_len(tab) != 3)
		{
			ft_freetab(&tab);
			tab = ft_strsplit(line, '-');
			if (ft_tab_len(tab) == 2)
			{
				ft_pipe_pushback(&data->pipe, tab);
				ft_freetab(&tab);
			}
			break;
		}
		ft_map_pushback(&data->map, tab, state);
		ft_strdel(&line);
		ft_freetab(&tab);
	}
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_comment(&line))
			break;
		printf("|%s|\n", line);
		tab = ft_strsplit(line, '-');
		if (ft_tab_len(tab) != 2)
		{
			ft_freetab(&tab);
			break;
		}
		ft_pipe_pushback(&data->pipe, tab);
		ft_strdel(&line);
		ft_freetab(&tab);
	}

}

int		ft_comment(char **line)
{
	while (line[0][0] == '#' && line[0][1] != '#')
	{
		printf("|%s|\n", *line);
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
		printf("|%s|\n", *line);
		if (ft_strequ(*line, "##start"))
			*state = 1;
		else if (ft_strequ(*line, "##end"))
			*state = 2;
		ft_strdel(line);
		get_next_line(0, line);
	}
}
