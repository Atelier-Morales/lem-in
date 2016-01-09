/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:43:16 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/23 20:53:28 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

static void			init_room(t_room *room)
{
	room->state = EMPTY;
	room->name = NULL;
	room->next = NULL;
	room->x = 0;
	room->y = 0;
}

static int			is_coordonne(char *str)
{
	if (((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
		|| ft_isdigit(*str))
	{
		if (*str == '-' || *str == '+')
			str++;
		if (!ft_str_isint(str, ft_strlen(str)))
			return (0);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

void				add_room(t_nest *nest, char *line, char **property)
{
	t_room		*room;
	t_room		*tmp;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		put_error(0);
	init_room(room);
	if (ft_strequ(*property, "start"))
	{
		room->property = START;
		room->state = nest->nb_ants;
	}
	else if (ft_strequ(*property, "end"))
		room->property = END;
	else
		room->property = NONE;
	room->name = ft_strcdup(line, ' ');
	room->x = nest->coords->x;
	room->y = nest->coords->y;
	ft_strdel(property);
	tmp = nest->rooms;
	nest->rooms = room;
	nest->rooms->next = tmp;
}

int					is_room(t_nest *nest, char *line)
{
	t_coord		*coord;
	char		**room;

	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		put_error(0);
	if (nest->pipes != NULL)
		return (0);
	room = ft_strsplit(line, ' ');
	if (ft_tabcount(room) != 3)
		return (0);
	while (*room[0])
	{
		if (!ft_isalnum(*room[0]))
			return (0);
		room[0]++;
	}
	if (!is_coordonne(room[1]) || !is_coordonne(room[2]))
		return (0);
	coord->x = ft_atoi(room[1]);
	coord->y = ft_atoi(room[2]);
	nest->coords = coord;
	if (!check_coordonne(nest, coord))
		return (0);
	return (1);
}

void				revers_room(t_room **files)
{
	t_room		*tmp1;
	t_room		*tmp2;

	if (*files != NULL)
	{
		tmp1 = (*files)->next;
		(*files)->next = NULL;
		while (tmp1 != NULL)
		{
			tmp2 = tmp1->next;
			tmp1->next = *files;
			(*files) = tmp1;
			tmp1 = tmp2;
		}
	}
}
