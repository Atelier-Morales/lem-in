/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:52:27 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/27 15:43:57 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	if (s != NULL)
	{
		i = 0;
		dest = (char *) malloc((len + 1) * sizeof(*s));
		if (dest == NULL)
			return (NULL);
		while (i < len && s[start + i] != '\0')
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
