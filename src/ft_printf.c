/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 08:41:17 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/25 18:56:12 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list		ap;
	size_t		size;
	char		*tmp;
	t_param		list;

	va_start(ap, str);
	size = 0;
	ft_param_nul(&list);
	while (*str)
	{
		tmp = ft_strchr(str, '%');
		if (tmp == NULL)
		{
			ft_putstr(str);
			return (size + ft_strlen(str));
		}
		else
		{
			if (tmp > str)
				size += ft_putnstr(str, tmp - str);
			str = tmp + 1;
			if (*str == '\0')
				return (size);
			else
				size += ft_percent(ap, &str, list);
		}
		str++;
	}
	va_end(ap);
	return (size);
}
