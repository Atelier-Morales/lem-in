/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:01:07 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/23 20:22:18 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

int				main(int ac, char **av)
{
	t_nest		*nest;
	t_room		*end;

	(void)av;
	if (ac != 1)
		put_error(2);
	nest = build_nest();
	put_result(nest);
	end = nest->rooms;
	while (end && end->property != END)
		end = end->next;
	while (end && end->state != nest->nb_ants)
	{
		if (move_ants(nest->ants, nest->pipes) == 0)
			break ;
		ft_putchar('\n');
	}
	return (0);
}
