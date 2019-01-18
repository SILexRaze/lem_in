/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:11:19 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/18 03:07:15 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ant_calcul(t_data *data, size_t *n)
{
	size_t	medant;
	size_t	medpath;
	size_t	nbpipe;
	size_t	i;

	i = 0;
	nbpipe = 0;
	medpath = 0;
	nbpipe = tab_struc_len(data->path_tab);
	//medant = *n / nbpipe;
	medant = 1;
	if (medant == 0)
		medant = 1;
	while (data->path_tab[i])
	{
		medpath += data->path_tab[i]->size;
		i++;
	}
	medpath = medpath / nbpipe;
	//printf("medant=%zu\tmedpath=%zu\n", medant, medpath);
	dispatch_ant(medant, medpath, data, n);
	return (0);
}

int		dispatch_ant(size_t medant, size_t medpath, t_data *data, size_t *n)
{
	size_t		i;
	int			test;
	long long	count;
	long long	diff;
	long long	test2;
	t_path		**tmp;

	i = 0;
	test = 0;
	diff = 0;
	tmp = data->path_tab;
	while (tmp[i] && (*n))
	{
		count = medpath - tmp[i]->size;
//		printf("COUNT=%lld|\tI=%zu\n", count, i);
		if (i > 0)
		{
			test = tmp[i - 1]->ant;
			diff = tmp[i]->size - tmp[i - 1]->size + 1;
		}
//		printf("diff=%lld\tn=%zu\n", diff, *n);
		if (diff <= test)
		{
			tmp[i]->ant += medant;
			test2 = *n - medant;
			if (test2 > 0)
				(*n) -= medant;
			else
				*n = -test2;
		}
		i++;
	}
	return (0);
}

void	newpathfinder(t_data *data)
{
	size_t	nant;
	size_t	i;

	nant = data->ant;
	while (nant)
	{
		ant_calcul(data, &nant);
//		printf("%zu|\n", nant);
		i = 0;
		while (data->path_tab[i])
		{
//			printf("tmp[%zu]=%ld\n", i, data->path_tab[i]->ant);
			i++;
		}
	}
}
