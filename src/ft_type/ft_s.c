/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:30:23 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/04/25 17:54:08 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_s(t_param list, char *s)
{
	int	tmp;
	int	size;

	size = 0;
	tmp = ft_strlen(s);
	if (list.width > 0 && list.width > tmp && list.minus == 0)
		size += ft_print_symb(' ', list.width - tmp);
	ft_putstr(s);
	size += ft_strlen(s);
	if (list.width > 0 && list.width > tmp && list.minus == 1)
		size += ft_print_symb(' ', list.width - tmp);
	return (size);
}
