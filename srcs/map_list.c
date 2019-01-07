/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:32:53 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/07 13:53:17 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map	*ft_map_create_elem(char **tab, int state)
{
	t_map	*new;

	if (!(new = (t_map*)ft_memalloc(sizeof(t_map))))
		exit(0);
	new->name = ft_strdup(tab[0]);
	new->x = ft_sizetoi(tab[1]);
	new->y = ft_sizetoi(tab[2]);
	new->state = state;
	new->pipe = NULL;
	new->next = NULL;
	return (new);
}

void	ft_map_pushback(t_map **begin_list, char **tab, int state)
{
	t_map	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_map_create_elem(tab, state);
	}
	else
		*begin_list = ft_map_create_elem(tab, state);
}

t_pipe	*ft_pipe_create_elem(char **tab)
{
	t_pipe	*new;

	if (!(new = (t_pipe*)ft_memalloc(sizeof(t_pipe))))
		exit(0);
	new->arg1 = ft_strdup(tab[0]);
	new->arg2 = ft_strdup(tab[1]);
	new->next = NULL;
	return (new);
}

void	ft_pipe_pushback(t_pipe **begin_list, char **tab)
{
	t_pipe	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_pipe_create_elem(tab);
	}
	else
		*begin_list = ft_pipe_create_elem(tab);
}

/*
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
