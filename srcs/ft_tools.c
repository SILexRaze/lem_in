/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:30:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/07 13:49:29 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t		ft_sizetoi(char *str)
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

int		ft_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_freetab(char ***tab)
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
