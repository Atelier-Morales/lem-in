/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 14:53:21 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/01 14:53:26 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem-in.h"

int                 display_error(char *msg)
{
    if (msg)
        ft_putendl(msg);
    else
        ft_putendl("Nothing on standard input. Operation aborted.");
    return (0);
}

int                 check_ants(char *line)
{
    while (*line == ' ' || *line == '\t')
        line++;
    if (ft_strlen(line) >= 10 && ft_strcmp(line, "2147483647") >= 0)
        return (0);
    while (*line)
    {
        if (!ft_isdigit(*line) && *line != ' ' && *line != '\t')
            return (0);
        line++;
    }
    return (1);
}

int                 check_coord(t_gallery *gal, int x, int y)
{
    t_room          *tmp;

    if (!gal->room)
        return (1);
    tmp = gal->room;
    while (tmp)
    {
        if (x == gal->room->x && y == gal->room->y)
            return (0);
        tmp = tmp->next;
    }
    return (1)
}

int                 is_coord(char *str)
{
    if (((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
            || ft_isdigit(*str))
    {
        if (*str == '-' || *str == '+')
            ++str;
        if (!ft_str_isint(str, ft_strlen(str)))
            return (0);
        while (*str)
        {
            if (!ft_isdigit(*str))
                return (0);
            ++str;
        }
        return (1);
    }
    return (0);
}

static int		is_newname(t_gallery *gal, char *line)
{
    t_room	*tmp;

    tmp = gal->room;
    while (tmp)
    {
        if (ft_strequ(tmp->name, ft_strcdup(line, ' ')))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int                 check_room(t_gallery *gal, char *line)
{
    char            **room;

    if (gal->tube)
        return (0);
    room = ft_strsplit(line, ' ');
    if (count_str(room) != 3)
        return (0);
    while (*room[0])
    {
        if (!ft_isalnum(*room[0]))
            return (0);
        room[0]++;
    }
    if (!is_coord(room[1]) || !is_coord(room[2]))
        return (0);
    gal->x = ft_atoi(room[1]);
    gal->y = ft_atoi(room[2]);
    if (!check_coord(gal, gal->x, gal->y))
        return (0);
    return (1);
}

int                 check_repeated_attr(t_room *room)
{
    int             start;
    int             end;

    start = 0;
    end = 0;
    while (gal)
    {
        if (ft_strcmp(room->property, "start") == 0)
            ++start;
        if (ft_strcmp(room->property, "end") == 0)
            ++end;
        room = room->next;
    }
    if (start > 1 || end > 1)
        return (0);
    return (1);
}

static void			init_room(t_room *room)
{
    room->state = EMPTY;
    room->name = NULL;
    room->next = NULL;
    room->x = 0;
    room->y = 0;
}

void				add_room(t_gallery *gal, char *line, char **attr)
{
    t_room		*room;
    t_room		*tmp;

    if (!(room = (t_room *) malloc(sizeof(t_room))))
        put_error(0);
    init_room(room);
    if (ft_strequ(*attr, "start"))
    {
        room->attribute = START;
        room->state = nest->nb_ants;
    }
    else if (ft_strequ(*attr, "end"))
        room->attribute = END;
    else
        room->attribute = NONE;
    room->name = ft_strcdup(line, ' ');
    room->x = gal->x;
    room->y = gal->y;
    ft_strdel(attribute);
    tmp = gal->room;
    gal->room = room;
    gal->room->next = tmp;
}

void                connect_room(t_gallery *gal, char *line, char **attr)
{
    static int      i;

    if (check_room(gal, line) && i == 0 && is_newname(gal, line))
        add_room(gal, line, attr);
    else
    {
        i = 1;
        if (is_tube(gal->room, line) && gal->room)
            add_tube(gal, line, attr);
    }
}

int                 check_file_input(t_gallery *gal, char *line)
{
    static char     *attribute = NULL;

    if (!line)
        return (0);
    else if (*line == 'L')
        return (0);
    else if (*line == '#' && *(line + 1) != '#')
        return (1);
    else if (*line == '#' && *(line + 1) == '#')
    {
        if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
        {
            attribute = ft_strdup(line + 2);
            if (check_repeated_attr(gal->room) == 0)
                return (0);
        }
        else
            return (0);
    }
    else
        connect_room(gal, line, &attribute);
    return (1);
}

int                 main(int ac, char **av)
{
    t_gallery       *gal;
    char            *line;

    if (ac != 1)
        return (display_error());
    if (!(gal = (t_gallery *)malloc(sizeof(t_gallery))))
        return (display_error("could not create gallery"));
    gal->ant = NULL;
    gal->room = NULL;
    gal->tube = NULL;
    get_next_line(0, &line);
    if (!check_ants(line) || ft_atoi(line) == 0 || !line)
        return (display_error("Invalid file format"));
    gal->nb = ft_atoi(line);
    while (get_next_line(0, &line))
    {
        if (check_file_input(gal, line) == 0)
            break ;
    }

}
