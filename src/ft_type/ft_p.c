/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:16:42 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/25 14:56:17 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int		ft_p(t_param list, void *ptr)
{
	int				size;
	int				tmp;
	char			*str;

	size = 0;
	tmp = (int)ptr;
	str = ft_itoa_base(tmp, 16);
	tmp = ft_strlen(str);
	if (list.minus == 1 && list.width > tmp + 2)
		size += ft_print_symb(' ', list.width - tmp - 2);
	write(1, "0x", 2);
	ft_putstr(str);
	free(str);
	if (list.minus == 1 && list.width > tmp + 2)
		size += ft_print_symb(' ', list.width - tmp - 2);
	return (size);
}
