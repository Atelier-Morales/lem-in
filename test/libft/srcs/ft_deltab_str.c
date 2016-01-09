/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 18:34:18 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/10 18:51:46 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_del_str(char *str)
{
	free(str);
	str = NULL;
}

void		ft_deltab_str(char ***c_env)
{
	char	**temp;

	if (*c_env)
	{
		temp = *c_env;
		while (*temp)
			ft_del_str(*temp++);
		free(*c_env);
		*c_env = NULL;
	}
}
