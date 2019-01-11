/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_path_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:02:15 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/11 14:13:24 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	(t_path **path_tab, size_t len)
{
	t_path	*tmp;
	int		i;

	tmp = path_tab[i];
	while ((len - 1) > 0)
	{
		i = 0;
		while (i < (len - 1))
		{
			if (path_tab[i]->size > path_tab[i + 1]->size)
			{
				tmp = path[i];
				path[i] = path[i + 1];
				path[i + 1] = tmp;
			}
			i++;
		}
		len--;
	}
}
