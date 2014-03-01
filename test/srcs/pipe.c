/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:43:27 by tmerlier          #+#    #+#             */
/*   Updated: 2014/02/23 20:55:16 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

static t_room		*room_chr(t_room *rooms, char *name);

void				add_pipe(t_nest *nest, char *line, char **property)
{
	char		**tab;
	t_pipe		*new;
	t_pipe		*tmp;

	tab = ft_strsplit(line, '-');
	if (!(new = (t_pipe *) malloc(sizeof(t_pipe))))
		put_error(0);
	new->room1 = room_chr(nest->rooms, tab[0]);
	new->room2 = room_chr(nest->rooms, tab[1]);
	new->property = ft_strdup(*property);
	ft_strdel(property);
	tmp = nest->pipes;
	nest->pipes = new;
	nest->pipes->next = tmp;
}

int					is_pipe(t_room *rooms, char *line)
{
	char		**tab;
	char		*tmp;
	int			i;

	i = 0;
	tmp = line;
	while (*tmp++)
		if (*tmp == '-')
			i++;
	if (i != 1)
		return (0);
	tab = ft_strsplit(line, '-');
	if (ft_tabcount(tab) != 2)
		return (0);
	if (ft_strchr(tab[0], ' ') || ft_strchr(tab[1], ' '))
		return (0);
	if (tab[1] && tab[2] == NULL)
		if (room_chr(rooms, tab[0]) && room_chr(rooms, tab[1]))
			return (1);
	return (0);
}

static t_room		*room_chr(t_room *rooms, char *name)
{
	while (rooms && !ft_strequ(rooms->name, name))
		rooms = rooms->next;
	return (rooms);
}

void				revers_pipe(t_pipe **files)
{
	t_pipe		*tmp1;
	t_pipe		*tmp2;

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
