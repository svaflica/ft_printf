/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:53:56 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/24 16:35:59 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_percent(va_list ap, char *str, t_param *list)
{
	if (*str == '%')
		ft_putchar('%');
	else
	{
		ft_param_add(list, &str);
		ft_print_param(list, str);
	}
	return (str + 1);
}
