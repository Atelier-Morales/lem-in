/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:46:15 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/18 16:53:08 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) malloc(n * sizeof(src));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = *((char *)src + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = str[i];
		i++;
	}
	free(str);
	return (dest);
}
