/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 08:41:17 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/24 15:58:18 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_printf(char *str, ...)
{
	va_list		ap;
	t_param		*list;

	va_start(ap, str);
	list = ft_param_new();
	while (*str)
	{
		if (*str == '%')
			str = ft_percent(ap, str + 1, list);
		else
			ft_putchar(*str);
		str++;
	}
	free(list);
	va_end(ap);
}
