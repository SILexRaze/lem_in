/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:43:36 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/12 14:16:53 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_init_errdb(void)
{
	char	**tab;

	if (!(tab = (char **)ft_memalloc(sizeof(char *) * 14)))
		return (NULL);
	tab[0] = "Error (0) : Not enough arguments.\n";
	tab[1] = "Error (-1) : Room is already defined.\n";
	tab[2] = "Error (-2) : Coordinates mus be an integer.\n";
	tab[3] = "Error (-3) : Coordinates can't be negative.\n";
	tab[4] = "Error (-4) : Room name can't start with 'L'.\n";
	tab[5] = "Error (-5) : Room name can't start with '#'.\n";
	tab[6] = "Error (-6) : Only one connection can be declared per line.\n";
	tab[7] = "Error (-7) : No connection declared.\n";
	tab[8] = "Error (-8) : You can't connect a room to itself.\n";
	tab[9] = "Error (-9) : Destination of connection missing.\n";
	tab[10] = "Error (-10) : Too few/much connection arguments.\n";
	tab[11] = "Error (-11) : Connection already declared.\n";
	tab[12] = "Error (-12) : Room cannot overlap with another.\n";
	tab[13] = "Error (-13) : Bad start/end room declaration.\n";
	tab[14] = "Error (-14) : There is no path between start and end.\n";
	tab[15] = "Error (-15) : No connection declared.\n";
	return (tab);
}

void	ft_error(int n)
{
	char	**tab;

	tab = ft_init_errdb();
	ft_putstr_fd(tab[-1 * n], 2);
	free(tab);
	exit (n);
}
