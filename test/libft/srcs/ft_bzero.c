/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:39:57 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/22 20:48:52 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_bzero(void *s, size_t n)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = s;
	while (n != 0)
	{
		s1[i] = 0;
		i++;
		n--;
	}
}
