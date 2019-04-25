/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:52:41 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/25 11:10:12 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int         ft_c(t_param list, int c)
{
    int size;

    size = 0;
    if (list.zero == 1 && list.width > 1)
        size += ft_print_symb('0', list.width - 1);
    ft_putchar(c);
    if (list.minus == 1 && list.width > 1)
        size += ft_print_symb(' ',  list.width - 1);
    return (size);
}