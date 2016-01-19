/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 19:05:31 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/23 05:25:58 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/lem_in.h"

static int		startend_pipe(t_nest *nest)
{
	t_pipe	*tmp;
	int		check;

	check = 0;
	tmp = nest->pipes;
	while (tmp)
	{
		if (tmp->room1->property == START || tmp->room1->property == END)
			check++;
		if (tmp->room2->property == START || tmp->room2->property == END)
			check++;
		tmp = tmp->next;
	}
	if (check >= 2)
		return (0);
	return (1);
}

static int		check_exit(t_nest *nest)
{
	t_room	*room_tmp;
	t_pipe	*pipe_tmp;
	int		connection;

	room_tmp = nest->rooms;
	while (room_tmp)
	{
		connection = 0;
		pipe_tmp = nest->pipes;
		while (pipe_tmp)
		{
			if (ft_strequ(pipe_tmp->room1->name, room_tmp->name)
					|| ft_strequ(pipe_tmp->room2->name, room_tmp->name))
				connection++;
			pipe_tmp = pipe_tmp->next;
		}
		if (room_tmp->property != NONE && connection < 1)
			return (1);
		room_tmp = room_tmp->next;
	}
	return (0);
}

int				check_xy(t_nest *nest, t_coord *coord)
{
	t_room		*tmp;

	if (!nest->rooms)
		return (1);
	tmp = nest->rooms;
	while (tmp)
	{
		if (coord->x == nest->rooms->x && coord->y == nest->rooms->y)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				check_rules(t_nest *nest)
{
	t_room	*tmp;
	int		start;
	int		end;

	start = 0;
	end = 0;
	tmp = nest->rooms;
	while (tmp)
	{
		if (tmp->property == START)
			start++;
		if (tmp->property == END)
			end++;
		tmp = tmp->next;
	}
	if (start > 1 || end > 1)
		return (1);
	return (0);
}

int				is_doable(t_nest *nest)
{
	if (nest->gates != 2)
		put_error(1);
	if (!nest->rooms)
		put_error(1);
	if (!nest->pipes)
		put_error(1);
	if (startend_pipe(nest))
		put_error(1);
	if (check_exit(nest))
		put_error(1);
	return (1);
}
