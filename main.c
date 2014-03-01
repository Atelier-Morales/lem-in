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

    }

}
