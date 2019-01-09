/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:43:46 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/09 01:05:42 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isroom(char *line, t_data *data)
{
	char	**tab;
	t_map	*tmp;

	tmp = data->map;
	tab = ft_strsplit(line, 32);
	if (ft_tab_len(tab) != 3)
		return (0);
	while (tmp)
	{
		if (ft_strequ(tab[0], tmp->name) == 1)
			return (-1);
		tmp = tmp->next;
	}
	if (tab[0][0] == 'L')
		return (-4);
	else if (tab[0][0] == '#' && tab[0][1] != '#')
		return (-5);
	if (ft_iscoord(tab) < 0)
		return (ft_iscoord(tab));
	return (1);
}

int		ft_iscoord(char **tab)
{
	if (!ft_strisdigit(tab[1]) || !ft_strisdigit(tab[2]))
		return (-2);
	if (tab[1][0] == '-' || tab[2][0] == '-')
		return (-3);
	return (1);
}

int		ft_ispipe(char *line, t_data *data)
{
	char	**tab;
	int		i;
	int		j;
	t_map	*tmp;

	i = 0;
	j = 0;
	tmp = data->map;
	tab = ft_strsplit(line, '-');
	if (ft_isminus(line) < 0)
		return (ft_isminus(line));
	if (ft_tab_len(tab) != 2)
		return (-10);
	while (tmp)
	{
		if (ft_strequ(tmp->name, tab[0]) == 1)
			i++;
		if (ft_strequ(tmp->name, tab[1]) == 1)
			j++;
		tmp = tmp->next;
	}
	if (j > 1)
		return (-8);
	else if (j < 1)
		return (-9);
}

int		ft_isminus(char *line)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '-')
			k++;
		i++;
	}
	if (k > 1)
		return (-6);
	else if (k == 0)
		return (-7);
	else
		return (1);
}
