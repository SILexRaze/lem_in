/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:43:36 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/14 13:27:23 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(int n)
{
	if (n == -1)
		ft_putendl_fd("Error (-1) : Bad room declaration.", 2);
	else if (n == -2)	
		ft_putendl_fd("Error (-2) : Bad tunnel declaration.", 2);
	exit(n);
}
