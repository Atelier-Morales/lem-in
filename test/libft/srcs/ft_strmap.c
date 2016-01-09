/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:42:00 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/22 20:48:33 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	if (!(s == NULL || f == NULL))
	{
		i = ft_strlen((char *)s);
		dest = (char *) malloc((i + 1) * sizeof(dest));
		if (dest == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
			{
				dest[i] = f(s[i]);
				i++;
			}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
