/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_review.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:41:11 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/07 13:35:59 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lem_in.h"

void	printf_review(t_data *data)
{
	t_map	*tmp;
	t_pipe	*tmpipe;

	tmp = data->map;
	tmpipe = data->pipe;
	printf("ant= %zu\n\n", data->ant);
	while (tmp)
	{
		printf("name= %s\t", tmp->name);
		printf("x= %zu\t", tmp->x);
		printf("y= %zu\t", tmp->y);
		printf("state= %d\t", tmp->state);
		printf("nbant= %zu\t", tmp->nbant);
		printf("nameant= %zu\t\n\n", tmp->nameant);

		tmp = tmp->next;
	}
	while (tmpipe)
	{
		printf("arg1= %s\t", tmpipe->arg1);
		printf("arg2= %s\t\n", tmpipe->arg2);
		tmpipe = tmpipe->next;
	}
}
