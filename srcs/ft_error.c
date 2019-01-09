/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:43:36 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/09 15:54:04 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_init_errdb(void)
{
	char	**tab;

	if (!(tab = (char **)ft_memalloc(sizeof(char *) * 14)))
		return (NULL);
	tab[0] = "(Error 0) : Not enough arguments.";
	tab[1] = "(Error -1) : Room is already defined.";
	tab[2] = "(Error -2) : Coordinates mus be an integer.";
	tab[3] = "(Error -3) : Coordinates can't be negative.";
	tab[4] = "(Error -4) : Room name can't start with 'L'.";
	tab[5] = "(Error -5) : Room name can't start with '#'.";
	tab[6] = "(Error -6) : Only one connection can be declared per line.";
	tab[7] = "(Error -7) : No connection declared.";
	tab[8] = "(Error -8) : You can't connect a room to itself.";
	tab[9] = "(Error -9) : Destination of connection missing.";
	tab[10] = "(Error -10) : Too few/much connection arguments.";
	tab[11] = "(Error -11) : Connection already declared.";
	tab[12] = "(Error -12) : Room cannot overlap with another.";
	tab[13] = "(Error -13) : You can only configure 1 start and 1 end room.";
}

void	ft_error(int n)
{
	char	**tab;

	tab = ft_init_errdb();
	ft_putendl_fd(tab[-1 * n], 2);
	free(tab);
	exit (0);
}
