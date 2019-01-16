/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:14:56 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/16 15:20:19 by vifonne          ###   ########.fr       */
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
	struct s_path	*freenext;
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
void				map_pushback(t_map **begin_list, char **tab, int state);
void				pipe_pushback(t_pipe **begin_list, char **tab);
void				printf_review(t_data *data); //remove when not needed
void				path_pushback(t_path **begin_list, t_map *room, size_t size);
t_map				*map_create_elem(char **tab, int state);
t_path				*path_create_elem(t_map *room, size_t size);
t_pipe				*pipe_create_elem(char **tab);
size_t				path_len(t_path **begin_list);
/*
**	CHECKER	MAP
*/
int					isvalid_pipe(t_data *data);
int					isvalid_map(t_data *data);
int					isvalid_room(t_data *data);
int					count_state(t_data *data);
/*
**	CHECKER STDIN
*/
int					isant(char *str, t_data *data);
int					isroom(char *str, t_data *data);
int					ispipe(char *str, t_data *data);
int					isinst(char *str);
int					isminus(char *line);
int					iscomment(char *str);
int					isstate(t_data *data);
/*
**	CHECKER PATH
*/
void				check_overlap_path(t_data *data);
void				merge_ifeq_path(t_data *data);
void				delete_path(t_data *data, int index);
/*
**	EXPLORE
*/
int					check_weight(t_map *tmp);
int					check_weight(t_map *tmp);
int					explore(t_map *tmp, t_data *data, t_map *prev);
int					priority(t_map *tmp);
void				sort_path_tab(t_path **path_tab, size_t len);
void				count_connex(t_map *tmp);
void				pathlist_totab(t_data *data);
size_t				npath(t_data *data);
size_t				pipesize(t_map **pipe);
/*
** ANT MOVE
*/
int					ant_move(t_path *path, t_path *prev, t_data *data, int n);
int					check_ant(t_data *data, int n);
int					ant_path(t_data *data);
void				print_ant(t_path *path);
/*
**	PARSER
*/
int					read_stdin(t_data *data);
void				link_pipe(t_data *data);
void				assign_pipe(t_map *map, t_data *data, size_t n);
t_map				*search_map_address(char *str, t_data *data);
/*
** TOOLS
*/
int					tab_len(char **str);
void				freetab(char ***tab);
void				free_map(t_data *data);
void				free_struct(t_data *data);
void				error(int n);
size_t				sizetoi(char *str);
size_t				pipe_nbr(t_map *map, t_pipe *pipe);
size_t				tab_struc_len(t_path **pipe);
#endif
