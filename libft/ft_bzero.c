/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:04:55 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/29 19:18:33 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		ft_bzero(void *s, size_t n)
{
	char	*d;

	if (n)
	{
		d = (char*)s;
		while (n--)
			*(d++) = 0;
	}
}
