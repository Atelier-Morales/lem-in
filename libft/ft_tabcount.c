/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:13:52 by fmorales          #+#    #+#             */
/*   Updated: 2016/01/08 16:14:09 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tabcount(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
