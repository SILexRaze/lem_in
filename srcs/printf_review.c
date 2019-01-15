/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_review.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:41:11 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/15 17:03:16 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lem_in.h"

void	printf_review(t_data *data)
{
//	t_map	*tmp;
//	t_path	*tmpath;
//	t_pipe	*tmpipe;
	t_path	*tmpath2;
	int		n;
	int		i;
/*
	tmp = data->map;
	tmpath = data->global_path;
	tmpipe = data->pipe;
	printf("ant= %zu\n\n", data->ant);
	while (tmp)
	{
		n = 0;
		printf("name= %s\t", tmp->name);
		printf("x= %zu\t", tmp->x);
		printf("y= %zu\t", tmp->y);
		printf("state= %d\t", tmp->state);
		printf("nbant= %zu\t", tmp->nbant);
		printf("nameant= %zu\t", tmp->nameant);
		printf("connex= %ld\t\n", tmp->connex);
		while (tmp->pipe && tmp->pipe[n])
		{
			printf("pipe= %s\n", tmp->pipe[n]->name);
			n++;
		}
		printf("\n");
		tmp = tmp->next;
	}
	while (tmpipe)
	{
		printf("arg1= %s\t", tmpipe->arg1);
		printf("arg2= %s\t\n", tmpipe->arg2);
		tmpipe = tmpipe->next;
	}
	*while (tmpath)
	{
	printf("%s->", tmpath->room->name);
		tmpath = tmpath->next;
	}
	printf("\n");*/
	n = ft_npath(data);
	i = 0;
	while (data->path_tab[i])
	{
		tmpath2 = data->path_tab[i];
		printf("%zu | ", data->path_tab[i]->size);
		printf("path[%d]", i);
		while(tmpath2)
		{
			printf("->%s", tmpath2->room->name);
			tmpath2 = tmpath2->next;
		}
	printf("\n\n");
		i++;
	}
}
