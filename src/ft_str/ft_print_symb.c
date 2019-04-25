/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_symb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:13:50 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/25 13:19:16 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int     ft_print_symb(int c, int size)
{
    int tmp;

    tmp = size;
    while (size--)
        ft_putchar(c);
    return (tmp);
}
