/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:15:49 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/04/28 16:31:21 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_prcnt(t_param list)
{
	int	size;

	size = 0;
	if (list.width > 1 && list.minus == 0)
		size += ft_print_symb(' ', list.width - 1);
	size += 1;
	ft_putchar('%');
	if (list.width > 1 && list.minus == 1)
		size += ft_print_symb(' ', list.width - 1);
	return (size);
}
