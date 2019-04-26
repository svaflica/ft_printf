/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:09:26 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/04/26 14:07:19 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	prec_neg(int *size, char *str, t_param list, int tmp)
{
	if (list.minus == 0 && list.zero == 0 && list.width - list.hasht > tmp)
		*size = ft_print_symb(' ', list.width - list.hasht - tmp);
	if (list.minus == 0 && list.zero == 1 && list.width - list.hasht > tmp)
		*size = ft_print_symb('0', list.width - list.hasht - tmp);
	*size += ft_print_symb('0', list.hasht);
	*size += ft_strlen(str);
	ft_putstr(str);
	if (list.minus == 1 && list.width - list.hasht > tmp)
		*size += ft_print_symb(' ', list.width - list.hasht - tmp);
}

static void	prec_pos(int *size, char *str, t_param list, int tmp)
{
	if (list.precision > tmp)
		*size += ft_print_symb('0', list.precision - tmp - list.hasht);
	*size += ft_print_symb('0', list.hasht);
	list.precision != 0 ? *size += ft_strlen(str) : 0;
	list.precision == 0 ? NULL : ft_putstr(str);
	if (list.width > (list.precision + tmp))
		*size += ft_print_symb(' ', list.width - list.precision);
}

int			ft_o(t_param list, unsigned int i)
{
	int		size;
	char	*str;
	int		tmp;

	size = 0;
	str = ft_itoa_base(i, 8);
	tmp = ft_strlen(str);
	if (list.precision == -1)
		prec_neg(&size, str, list, tmp);
	else
		prec_pos(&size, str, list, tmp);
	free(str);
	return (size);
}
