/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:41:11 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/22 18:22:42 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/lem_in.h"

void	put_error(int code)
{
	if (code == 0)
		ft_putstr_fd("Error: malloc fail\n", 2);
	else if (code == 1)
		ft_putstr_fd("ERROR\n", 2);
	else if (code == 2)
		ft_putstr_fd("Usage: ./lem-in < [map]\n", 2);
	exit(0);
}
