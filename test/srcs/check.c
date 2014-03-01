/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 19:05:31 by tmerlier          #+#    #+#             */
/*   Updated: 2014/02/23 05:25:58 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <lem-in.h>

static int		check_star_end(t_nest *nest);
static int		startend_pipe(t_nest *nest);

int				check_coordonne(t_nest *nest, t_coord *coord)
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
	if (!nest->rooms)
		put_error(1);
	if (check_star_end(nest))
		put_error(1);
	if (!nest->pipes)
		put_error(1);
	if (startend_pipe(nest))
		put_error(1);
	return (1);
}

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

static int		check_star_end(t_nest *nest)
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
	if (start == 1 && end == 1)
		return (0);
	return (1);
}
