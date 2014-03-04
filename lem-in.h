/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:17:50 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/01 17:17:53 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
 # define LEM_IN_H

typedef struct		s_room
{
    char			*name;
    char			attribute;
    int				state;
    int				x;
    int				y;
    struct s_room	*next;
}					t_room;

typedef struct		s_tube
{
    t_room			*room1;
    t_room			*room2;
    char			*attribute;
    struct s_tube	*next;
}					t_tube;

typedef struct		s_ant
{
    int				num;
    t_room			*pos;
    t_room			*previous;
    struct s_ant	*next;
}					t_ant;

typedef struct      s_gallery
{
    int             nb;
    int             x;
    int             y;
    t_tube          *tube;
    t_ant           *ant;
    t_room          *room;
}                   t_gallery;

#endif /* !LEM_IN_H */
