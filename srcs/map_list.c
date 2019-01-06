/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:32:53 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/06 16:31:43 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map	*ft_map_create_elem(char *name, int *coord)
{
	t_map	*new;

	if (!(new = (t_map*)ft_memalloc(sizeof(t_map))))
		exit(0);
	new->name = name;
	new->x = coord[0];
	new->y = coord[1];
	new->next = NULL;
	return (new);
}

/*
void	ft_map_pushback(t_map **begin_list, char *name, int *coord)
{
	t_map	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->tmp_next)
			tmp = tmp->tmp_next;
		tmp->tmp_next = ft_map_create_elem(name, coord);
	}
	else
		*begin_list = ft_map_create_elem(name, coord);
}

void	ft_map_pushfront(t_map **begin_list, char *name, int *coord)
{
	t_map	*tmp;

	if (*begin_list)
	{
		tmp = ft_map_create_elem(name, coord);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_map_create_elem(name, coord);
}

int		ft_map_size(t_map **begin_list)
{
	int		i;
	t_map	*tmp;

	i = 0;
	tmp = *begin_list;
	if (tmp)
	{
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

void	ft_map_clear(t_map **begin_list)
{
	t_map	*tmp;

	tmp = NULL;
	while (*begin_list)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	(*begin_list) = NULL;
}*/
