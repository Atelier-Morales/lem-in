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

typedef struct  s_gallery
{
    int         nb;
    t_tube      *tube;
    t_ant       *ant;
    t_room      *room;
}               t_gallery;

#endif /* !LEM_IN_H */
