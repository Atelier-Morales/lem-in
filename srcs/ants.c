/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 19:29:10 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/23 05:59:42 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/lem_in.h"

static int			is_int(char *line)
{
	int		len;

	len = ft_strlen(line);
	if (len >= 10 && ft_strcmp(line, "2147483647") >= 0)
		return (0);
	return (1);
}

static t_ant		*new_ant(t_room *room, int num)
{
	t_ant		*new;

	if (!(new = (t_ant *)malloc(sizeof(t_ant))))
		put_error(0);
	new->num = num;
	new->pos = room;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

int					is_ants(char *line)
{
	char		**test;

	test = ft_strsplit(line, ' ');
	if (ft_strlen(test[1]) > 0)
		return (0);
	while (*line == ' ' || *line == '\t')
		line++;
	if (!is_int(line))
		return (0);
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != ' ' && *line != '\t')
			return (0);
		line++;
	}
	return (1);
}

t_ant				*init_ants(int ants_nb, t_nest *nest)
{
	t_ant		*new;
	t_ant		*tmp;
	t_room		*tmp_r;

	new = NULL;
	tmp_r = nest->rooms;
	while (tmp_r && tmp_r->property != START)
		tmp_r = tmp_r->next;
	while (ants_nb)
	{
		tmp = new;
		new = new_ant(tmp_r, ants_nb--);
		new->next = tmp;
	}
	return (new);
}
