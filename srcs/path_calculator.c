/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:11:19 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/21 11:22:59 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		dispatch_ant(t_data *data, size_t *n)
{
	size_t		i;
	int			test;
	long long	diff;

	i = 0;
	test = 0;
	diff = 0;
	while (data->path_tab[i] && (*n))
	{
//		printf("COUNT=%lld|\tI=%zu\n", count, i);
		if (i > 0)
		{
			test = data->path_tab[i - 1]->ant;
			diff = data->path_tab[i]->size - data->path_tab[i - 1]->size + 1;
		}
//		printf("diff=%lld\tn=%zu\n", diff, *n);
		if (diff <= test)
		{
			data->path_tab[i]->ant += 1;
			if (*n - 1 > 0)
				(*n) -= 1;
			else
				*n = -(*n - 1);
		}
		i++;
	}
	return (0);
}

void	pathfinder(t_data *data)
{
	size_t	nant;
	size_t	i;

	nant = data->ant;
	while (nant)
	{
		dispatch_ant(data, &nant);
//		printf("%zu|\n", nant);
		i = 0;
		while (data->path_tab[i])
		{
//			printf("tmp[%zu]=%ld\n", i, data->path_tab[i]->ant);
			i++;
		}
	}
}
