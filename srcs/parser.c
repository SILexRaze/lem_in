/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:03:58 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/06 19:34:31 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_read_stdin(t_data *data)
{
	char	*line;
	char	**tab;

	if (get_next_line(0, &line) > 0)
	{
		t_data->ant = ft_sizetoi(line);
	}
	while (get_next_line(0, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		if (ft_tab_len(tab) != 3)
			break;
		ft_list_pushback(&data->tmp, ft_strdup(line), ft_strlen(line));
		ft_strdel(&line);
	}
	ft_print_list(&data->tmp);
}
