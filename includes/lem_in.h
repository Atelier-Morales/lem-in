/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:08:11 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/23 20:53:52 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define EMPTY		0
# define FULL		1
# define START		2
# define END		3
# define NONE		-1

typedef struct		s_room
{
	char			*name;
	char			property;
	int				state;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_pipe
{
	t_room			*room1;
	t_room			*room2;
	char			*property;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_ant
{
	int				num;
	t_room			*pos;
	t_room			*previous;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_nest
{
	int				nb_ants;
	int				gates;
	char			*start;
	char			*end;
	t_room			*rooms;
	t_pipe			*pipes;
	t_ant			*ants;
	t_coord			*coords;
}					t_nest;

t_ant				*init_ants(int nb, t_nest *nest);
int					is_ants(char *line);
int					move_ants(t_ant *ants, t_pipe *pipes);
t_nest				*build_nest(void);
void				add_room(t_nest *nest, char *line, char **property);
int					is_room(t_nest *nest, char *line);
void				add_pipe(t_nest *nest, char *line, char **property);
int					is_pipe(t_room *rooms, char *line);
void				put_path(int num, char *name);
int					check_rules(t_nest *nest);
int					is_doable(t_nest *nest);
void				put_error(int code);
int					check_xy(t_nest *nest, t_coord *coord);
void				put_result(t_nest *nest);
void				revers_room(t_room **files);
void				revers_pipe(t_pipe **files);

#endif
