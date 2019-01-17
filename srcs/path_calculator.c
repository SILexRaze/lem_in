/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:11:19 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/17 17:48:08 by vifonne          ###   ########.fr       */
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
	medant = *n / nbpipe;
	if (medant == 0)
		medant = 1;
	while (data->path_tab[i])
	{
		medpath += data->path_tab[i]->size;
		i++;
	}
	medpath = medpath / nbpipe;
	printf("medant=%zu\tmedpath=%zu\n", medant, medpath);
	dispatch_ant(medant, medpath, data, n);
	return (0);
}

int		dispatch_ant(size_t medant, size_t medpath, t_data *data, size_t *n)
{
	size_t		i;
	int			test;
	long long	count;
	t_path		**tmp;

	i = 0;
	test = 0;
	tmp = data->path_tab;
	while (tmp[i] && (*n))
	{
		count = medpath - tmp[i]->size + medant;
		printf("COUNT=%lld|I=%zu\n", count, i);
		if (count > 0)
		{
			tmp[i]->ant += medant;
			test = *n - medant;
			if (test > 0)
				(*n) -= medant;
			else
				*n = -test;
		}
		i++;
	}
	return (0);
}

void	newpathfinder(t_data *data)
{
	size_t	nant;

	nant = data->ant;
	while (nant)
	{
		ant_calcul(data, &nant);
		printf("%zu|\n", nant);
	}
	nant = 0;
	while (data->path_tab[nant])
	{
		printf("tmp[%zu]=%ld\n", nant, data->path_tab[nant]->ant);
		nant++;
	}
}
