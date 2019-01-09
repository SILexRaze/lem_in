/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:56 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/09 13:52:35 by vifonne          ###   ########.fr       */
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
	size_t			x;
	size_t			y;
	int				state;
	size_t			weight;
	size_t			nbant;
	size_t			nameant;
	struct s_map	**pipe;
	struct s_map	*next;
}					t_map;

typedef struct		s_pipe
{
	char			*arg1;
	char			*arg2;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_data
{
	t_map			*map;
	t_pipe			*pipe;
	size_t			ant;
}					t_data;

/*
**	LIST FUNCTION (t_pipe, t_map)
*/
t_map				*ft_map_create_elem(char **tab, int state);
void				ft_map_pushback(t_map **begin_list, char **tab, int state);
t_pipe				*ft_pipe_create_elem(char **tab);
void				ft_pipe_pushback(t_pipe **begin_list, char **tab);
void				printf_review(t_data *data); //remove when not needed
/*
**	CHECKER
*/
int					ft_isroom(t_data *data, char **tab);
int					ft_iscoord(char **tab, t_data *data);
int					ft_isminus(char *line);
int					ft_ispipe(char *line, t_data *data, char **tab);
int					ft_doublepipe(char **tab, t_data *data);
int					ft_isvalid_map(t_data *data);
int					ft_count_state(t_data *data);
int					ft_check_connection(t_map *tmp, t_map *prev);
int					ft_tab_struct_len(t_map **pipe);
/*
**	PARSER
*/
void				ft_read_stdin(t_data *data);
void				ft_state(char **line, int *state);
int					ft_skip_comment(char **line);
int					ft_parse_pipe(t_data *data);
int					ft_parse_room(t_data *data);
void				ft_link_pipe(t_data *data);
void				ft_assign_pipe(t_map *map, t_data *data, size_t n);
t_map				*ft_search_map_address(char *str, t_data *data);
size_t				ft_pipe_nbr(t_map *map, t_pipe *pipe);

/*
** TOOLS
*/
size_t				ft_sizetoi(char *str);
int					ft_tab_len(char **str);
void				ft_freetab(char ***tab);
#endif
