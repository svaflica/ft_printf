/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:44:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/25 15:48:55 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_d(t_param list, int i)
{
	int size;
	int n_di;

	n_di = ft_num_dig(i, 10);
	size = n_di;
	if (list.space == 1)
		ft_putchar(' ');
	if (list.zero == 1)
		size += ft_print_symb('0', list.width - n_di - list.space -
			(list.plus == 1 || i < 0));
	else if (list.minus == 0 && list.width > n_di + list.space +
			(list.plus == 1 || i < 0))
		size += ft_print_symb(' ', list.width - n_di - list.space -
			(list.plus == 1 || i < 0));
	if (list.plus == 1 && i >= 0)
		ft_putchar('+');
	ft_putnbr(i);
	if (list.minus == 1 && list.width > n_di + list.space +
		(list.plus == 1 || i < 0))
		size += ft_print_symb(' ', list.width - n_di - list.space -
			(list.plus == 1 || i < 0));
	return (size);
}
