/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:25:39 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/17 15:14:27 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

static t_room		*can_move(t_room *pos, t_room *prev, t_pipe *pipes)
{
	t_room		*res;

	if (pos->property == END)
		return (NULL);
	if ((res = end_near(pipes, pos)))
		return (res);
	while (pipes)
	{
		if (pos == pipes->room1 && (res = test_room(pipes->room2, pos, prev)))
			return (res);
		if (pos == pipes->room2 && (res = test_room(pipes->room1, pos, prev)))
			return (res);
		pipes = pipes->next;
	}
	return (NULL);
}

static t_room		*test_room(t_room *room, t_room *pos, t_room *prev)
{
	if (room->property == END)
		return (room);
	if (pos == room)
		return (NULL);
	if (room->property != START)
	{
		if (room != prev && room->state == EMPTY)
			return (room);
	}
	return (NULL);
}

static t_room		*end_near(t_pipe *pipes, t_room *pos)
{
	while (pipes)
	{
		if (pos == pipes->room1 && pipes->room2->property == END)
			return (pipes->room2);
		if (pos == pipes->room2 && pipes->room1->property == END)
			return (pipes->room1);
		pipes = pipes->next;
	}
	return (NULL);
}

int					move_ants(t_ant *ants, t_pipe *pipes)
{
	t_room		*next;
	int			res;

	res = 0;
	next = NULL;
	while (ants)
	{
		if ((next = can_move(ants->pos, ants->previous, pipes)))
		{
			if (res++)
				ft_putchar(' ');
			put_path(ants->num, next->name);
			ants->previous = ants->pos;
			ants->pos->state = ants->pos->state - 1;
			next->state = next->state + 1;
			ants->pos = next;
		}
		ants = ants->next;
	}
	return (res);
}
