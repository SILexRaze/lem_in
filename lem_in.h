/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:56 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/14 17:04:52 by vifonne          ###   ########.fr       */
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
	long			connex;
	size_t			n;
	struct s_map	**pipe;
	struct s_map	*next;
}					t_map;

typedef struct		s_pipe
{
	char			*arg1;
	char			*arg2;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_path
{
	t_map			*room;
	size_t			size;
	struct s_path	*next;
}					t_path;

typedef struct		s_data
{
	t_map			*map;
	t_map			*start;
	t_pipe			*pipe;
	t_path			*global_path;
	t_path			**path_tab;
	t_list			*raw_input;
	int				errcode;
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
t_path				*ft_path_create_elem(t_map *room, size_t size);
void				ft_path_pushback(t_path **begin_list, t_map *room, size_t size);
size_t				ft_path_len(t_path **begin_list);
/*
**	CHECKER
*/
int					ft_isvalid_pipe(t_data *data);
int					ft_isvalid_map(t_data *data);
int					ft_isvalid_room(t_data *data);
int					ft_count_state(t_data *data);
int					ft_tab_struct_len(t_map **pipe);
/*
**	EXPLORE
*/
int					ft_check_weight(t_map *tmp);
int					ft_check_weight(t_map *tmp);
void				ft_count_connex(t_map *tmp);
int					ft_explore(t_map *tmp, t_data *data, t_map *prev);
int					ft_priority(t_map *tmp);
size_t				ft_pipesize(t_map **pipe);
void				sort_path_tab(t_path **path_tab, size_t len);
size_t				ft_npath(t_data *data);
void				ft_pathlist_totab(t_data *data);
/*
** ANT MOVE
*/
int					ant_move(t_path *path, t_path *prev, t_data *data);
int					check_ant(t_path *path);
int					ant_path(t_data *data);
void				print_ant(t_path *path);
/*
**	PARSER
*/
int					ft_isant(char *str, t_data *data);
int					ft_isroom(char *str, t_data *data);
int					ft_ispipe(char *str, t_data *data);
int					ft_isinst(char *str);
int					ft_isminus(char *line);
int					ft_iscomment(char *str);
int					ft_isstate(t_data *data);
int					ft_read_stdin(t_data *data);
void				ft_link_pipe(t_data *data);
void				ft_assign_pipe(t_map *map, t_data *data, size_t n);
t_map				*ft_search_map_address(char *str, t_data *data);
size_t				ft_pipe_nbr(t_map *map, t_pipe *pipe);
/*
** TOOLS
*/
int					ft_tab_len(char **str);
size_t				ft_sizetoi(char *str);
void				ft_freetab(char ***tab);
void				ft_free_map(t_data *data);
void				ft_free_struct(t_data *data);
void				ft_error(int n);
#endif
