/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:11:19 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/17 13:58:24 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ant_calcul(t_data *data)
{
	size_t	medant;
	size_t	medpath;
	size_t	nbpipe;
	size_t	i;

	i = 0;
	nbpipe = 0;
	medpath = 0;
	nbpipe = tab_struc_len(data->path_tab);
	medant = data->ant / nbpipe;
	while (data->path_tab[i])
	{
		medpath += data->path_tab[i]->size;
		i++;
	}
	medpath = medpath / nbpipe;
	printf("medant=%zu\tmedpath=%zu\n", medant, medpath);
	dispatch_ant(medant, medpath, data);
	return (0);
}

int		dispatch_ant(size_t medant, size_t medpath, t_data *data)
{
	size_t	i;
	t_path	**tmp;

	i = 0;
	tmp = data->path_tab;
	while (tmp[i])
	{
		tmp[i]->ant = medant + medpath - tmp[i]->size;
		printf("tmp[%zu]=%ld\n", i, tmp[i]->ant);
		i++;
	}
	return (0);
}
