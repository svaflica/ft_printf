/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:57:38 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/28 13:00:27 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int		ft_putnstr(char *str, int size)
{
	int i;

	i = 0;
	while (*str && i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
