/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 19:42:35 by tmerlier          #+#    #+#             */
/*   Updated: 2014/02/23 21:22:56 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

static t_nest	*new_nest(void);
static int		add_line(t_nest *nest, char *line);
static void		create_room_pipe(t_nest *nest, char *line, char **property);
static int		is_newname(t_nest *nest, char *line);

t_nest			*build_nest(void)
{
	char	*line;
	t_nest	*nest;

	nest = new_nest();
	get_next_line(0, &line);
	if (!is_ants(line) || ft_atoi(line) == 0 || line == NULL)
		put_error(1);
	nest->nb_ants = ft_atoi(line);
	while (get_next_line(0, &line))
	{
		if (add_line(nest, line))
			break ;
	}
	if (is_doable(nest))
		nest->ants = init_ants(nest->nb_ants, nest);
	return (nest);
}

static t_nest	*new_nest(void)
{
	t_nest	*new;

	if (!(new = (t_nest *) malloc(sizeof(t_nest))))
		put_error(0);
	new->ants = NULL;
	new->rooms = NULL;
	new->pipes = NULL;
	return (new);
}

static int		add_line(t_nest *nest, char *line)
{
	static char		*property = NULL;

	if (line == NULL)
		return (1);
	else if (*line == 'L')
		return (1);
	else if ((*line == '#' && *(line + 1) == '#'))
	{
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		{
			property = ft_strdup(line + 2);
			if (check_rules(nest))
				return (1);
		}
		else
			return (1);
	}
	else if (*line == '#' && *(line + 1) != '#')
		return (0);
	else
		create_room_pipe(nest, line, &property);
	return (0);
}

static void		create_room_pipe(t_nest *nest, char *line, char **property)
{
	static int		i = 0;

	if (is_room(nest, line) && i == 0 && is_newname(nest, line))
		add_room(nest, line, property);
	else
	{
		i = 1;
		if (is_pipe(nest->rooms, line) && nest->rooms != NULL)
			add_pipe(nest, line, property);
	}
}

static int		is_newname(t_nest *nest, char *line)
{
	t_room	*tmp;

	tmp = nest->rooms;
	while (tmp)
	{
		if (ft_strequ(tmp->name, ft_strcdup(line, ' ')))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
