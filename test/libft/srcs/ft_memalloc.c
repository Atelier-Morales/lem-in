/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:12:40 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/22 20:48:46 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void		*ft_memalloc(size_t size)
{
	void	*str;

	str = (void *) malloc(size * sizeof(*str));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
