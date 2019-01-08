/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:43:46 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/08 15:05:54 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isroom(char *line, t_data *data)
{
	char	**tab;
	t_map	*tmp;

	tmp = data->map;
	if (!(tab = ft_strsplit(line, 32)))
		exit(0);
	if (ft_tab_len(tab) != 3)
		return (0);
	while (tmp)
	{
		if (ft_strequ(tab[0], tmp->name) == 1)
			return (-1);
		tmp = tmp->next;
	}
	if (!ft_strisdigit(tab[1]) || !ft_strisdigit(tab[2]))
		return (-2);
	if (tab[1][0] == '-' || tab[1][0] == '-')
		return (-3);
}
