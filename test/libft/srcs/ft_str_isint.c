/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 20:16:16 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/23 03:19:12 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_str_isint(char *str, int len)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (len == 10)
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	}
	else if (len > 10)
		return (0);
	return (1);
}
