/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:44:01 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/13 16:22:38 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** fontion recursive de deplacement des fourmis
** condition d'arret: quand toutes les foumis sont passer de start a end
** check si la room next est vide, si oui faire avancer la formis sinon faire avancer la fourmis de la room next ect
*/

int		ant_move(t_map *path, t_data *data)
{
	while (path->nbant)
	{
	if (path->next->nbant < 0 && state == 0)
		return (ant_move(path->next));
	path->next->nameant = ant - start->nbant;
	path->nbant--;
	path->next->nameant = path->nameant;
	path->nameant = 0;
	nbant--;
	}
	return (0);
}
