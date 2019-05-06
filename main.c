/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/06 18:22:07 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c ./src/ft_buf/*.c && ./a.out
int main (void)
{
	ft_printf("%lu\n", -42);
	printf("%lu\n", -42);
	ft_printf("%lu\n", (unsigned long)-42);
	printf("%lu", (unsigned long)-42);
}
