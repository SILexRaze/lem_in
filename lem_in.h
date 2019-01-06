/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:56 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/06 16:25:48 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_map
{
	char			*name;
	int				x;
	int				y;
	struct s_map	**next;
}					t_map;

typedef struct		s_data
{
	t_map			*map;
	t_list			*tmp;
	size_t			ant;
}					t_data;

/*
**	LIST FUNCTION (t_pipe, t_map)
*/
t_map				*ft_map_create_elem(char *name, int *coord);
void				ft_map_pushback(t_map **begin_list, char *name, int *coord);
void				ft_map_print(t_map **begin_list);

/*
**	PARSER
*/
void				ft_read_stdin(t_data *data);
#endif
