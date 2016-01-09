/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:14:37 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/22 20:48:36 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		length;

	i = 0;
	s2 = 0;
	if (s1 == 0)
		return (s2);
	length = ft_strlen((char *)s1);
	s2 = (char *) malloc(sizeof(*s1) * (length + 1));
	if (s2 == NULL)
		return (s2);
	while (i < length)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
