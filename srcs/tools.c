/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:30:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/14 17:00:08 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	sizetoi(char *str)
{
	size_t i;
	size_t dst;

	i = 0;
	dst = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		dst = dst * 10 + str[i] - 48;
		i++;
	}
	return (dst);
}

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	freetab(char ***tab)
{
	size_t i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

size_t	pipesize(t_map **pipe)
{
	size_t	i;

	i = 0;
	while (pipe[i])
		i++;
	return (i);
}
