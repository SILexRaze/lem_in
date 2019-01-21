/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_connex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 01:37:31 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/21 14:38:59 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	count_connex2(t_map *tmp, t_map *prev)
{
	size_t  i;
	i = 0;
	//printf("%s\tconnex=%ld\n",tmp->name, tmp->connex);
	while(tmp->pipe[i] && (tmp->connex == 0 || tmp->connex == -2))
	{
		if (tmp->state == 2)
			break ;
		if (tmp->pipe[i]->connex == 0  && tmp->pipe[i] != prev)
		{
			tmp->connex = -2;
			count_connex2(tmp->pipe[i], tmp);
		}
		i++;
	}
	if (check_dead_end(tmp, prev) && tmp->state == 0)
		tmp->connex = -1;
	else if (tmp->state != 0)
		tmp->connex = pipesize(tmp->pipe);
	else
		tmp->connex = count_real_pipe (tmp, prev);
}

int		count_real_pipe(t_map *map, t_map *prev)
{
	t_map	**tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tmp = map->pipe;
	while (tmp[i])
	{
		if ((tmp[i]->connex > 0 || tmp[i]->connex == -2) && tmp[i] != prev)
			j++;
		i++;
	}
	return(j);
}

int		check_dead_end(t_map *map, t_map *prev)
{
	t_map	**tmp;
	size_t	i;

	i = 0;
	tmp = map->pipe;
	while (tmp[i]) 
	{
		if ((tmp[i]->connex > 0 || tmp[i]->connex == -2)&& tmp[i] != prev)
			return (0);
		i++;
	}
	return(1);

}
