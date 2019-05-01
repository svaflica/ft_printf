/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:16:42 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 11:07:05 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int		ft_p(t_param list, void *ptr)
{
	int				size;
	long long		tmp;
	char			*str;

	tmp = (unsigned long long)ptr;
	str = ft_itoa_base_ll(tmp, 16);
	size = ft_strlen(str);
	tmp = size;
	if (list.minus == 1 && list.width > tmp + 2)
		size += ft_print_symb(' ', list.width - tmp - 2);
	write(1, "0x", 2);
	size += 2;
	ft_putstr(str);
	free(str);
	if (list.minus == 1 && list.width > tmp + 2)
		size += ft_print_symb(' ', list.width - tmp - 2);
	return (size);
}
