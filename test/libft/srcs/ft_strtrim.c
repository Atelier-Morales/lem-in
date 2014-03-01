/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 19:25:50 by tmerlier          #+#    #+#             */
/*   Updated: 2014/02/22 20:48:23 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	if ((char *)s == NULL)
		return (NULL);
	len = ft_strlen((char *)s) - 1;
	i = 0;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i > len)
	{
		str = (char *) malloc(1 * sizeof(*s));
		*str = 0;
		return (str);
	}
	if ((str = (char *) malloc((len - i + 2) * sizeof(*s))) == NULL)
		return (NULL);
	if (i == 0 && len == ft_strlen((char *)s) - 1)
		return (ft_strdup((char *)s));
	ft_strncpy(str, s + i, len - i + 1);
	str[len - i + 1] = 0;
	return (str);
}
