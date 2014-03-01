/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:23:23 by tmerlier          #+#    #+#             */
/*   Updated: 2014/02/23 20:55:09 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lem-in.h>

static void		put_rooms(t_nest *nest);
static void		put_pipes(t_nest *nest);

void			put_path(int num, char *name)
{
	ft_putchar('L');
	ft_putnbr(num);
	ft_putchar('-');
	ft_putstr(name);
}

void			put_result(t_nest *nest)
{
	ft_putnbr(nest->nb_ants);
	ft_putchar('\n');
	put_rooms(nest);
	put_pipes(nest);
	ft_putchar('\n');
}

static void		put_rooms(t_nest *nest)
{
	t_room		*tmp;

	revers_room(&nest->rooms);
	tmp = nest->rooms;
	while (tmp)
	{
		if (tmp->property == START)
			ft_putstr("##start\n");
		if (tmp->property == END)
			ft_putstr("##end\n");
		ft_putstr(tmp->name);
		ft_putchar(' ');
		ft_putnbr(tmp->x);
		ft_putchar(' ');
		ft_putnbr(tmp->y);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	revers_room(&nest->rooms);
}

static void		put_pipes(t_nest *nest)
{
	t_pipe		*tmp;

	revers_pipe(&nest->pipes);
	tmp = nest->pipes;
	while (tmp)
	{
		ft_putstr(tmp->room1->name);
		ft_putchar('-');
		ft_putstr(tmp->room2->name);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	revers_pipe(&nest->pipes);
}
