/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:09:32 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/21 16:12:42 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	if ((n >= 10) || (n <= (-10)))
	{
		ft_putnbr(n / 10);
	}
	else if (n < 0)
		ft_putchar('-');
	if (n < 0)
		ft_putchar('0' - (n % 10));
	else
		ft_putchar('0' + (n % 10));
}
