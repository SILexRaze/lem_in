/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:03:58 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/13 14:49:53 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*void	ft_read_stdin(t_data *data)
  {
  char	*line;
  t_map	*tmp;

  if (get_next_line(0, &line) > 0)
  {
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
  }*/

int		ft_read_stdin(t_data *data)
{
	char	*line;
	int		ret;
	int		trig;

	trig = 0;
	ret = 0;
	if (get_next_line(0, &line) > 0 && (ret = ft_isant(line)) == 1)
		ft_list_pushback(&data->raw_input, ft_strdup(line), ft_strlen(line));
	else
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isroom(line, data) == 1 || ft_ispipe(line) == 1 || ft_isinst(line) > 0)
		{
			if (trig == 0 && (ret = ft_isroom(line, data)) == 1)
				ft_list_pushback(&data->raw_input, ft_strdup(line), ft_strlen(line));
			else if (ft_isinst(line) > 0)
				ft_list_pushback(&data->raw_input, ft_strdup(line), ft_strlen(line));
			else
			{
				trig = 1;
			}
			if (trig == 1 && ft_ispipe(line) == 1)
				ft_list_pushback(&data->raw_input, ft_strdup(line), ft_strlen(line));
			else if (trig == 1)
				return (-1);
		}
		ft_strdel(&line);
	}
	return (1);
}

int			ft_isant(char *str)
{
	if (!ft_strisdigit(str))
		return (0);
	return (1);
}

int			ft_isroom(char *str, t_data *data)
{
	char	**tab;

	tab = ft_strsplit(str, 32);
	if (ft_tab_len(tab) != 3 || tab[0][0] == 'L')
	{
		ft_freetab(&tab);
		return (0);
	}
	if (!ft_strisdigit(tab[1]) || !ft_strisdigit(tab[2]))
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

int			ft_isstate(t_data *data)
{
	t_list	*tmp;

	tmp = data->raw_input;
	while (tmp->next)
		tmp = tmp->next;
	if (ft_isinst(tmp->data) == 1)
	{
		if (ft_strequ(tmp->data, "##end") == 1)
			return (2);
		else
			return (1);
	}
	return (0);
}

int			ft_ispipe(char *str)
{
	char	**tab;

	tab = ft_strsplit(str, '-');
	if (ft_tab_len(tab) != 2 || ft_isminus(str) < 0)
	{
		ft_freetab(&tab);
		return (0);
	}
	ft_freetab(&tab);
	return (1);
}

int			ft_isinst(char *str)
{
	if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		return (1);
	else if (str[0] == '#' && str[1] == '#')
		return (2);
	return (0);
}

int			ft_iscomment(char *str)
{
	if (str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

/*int		ft_parse_room(t_data *data)
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
		ft_strdel(line);
		get_next_line(0, line);
	}
}*/
