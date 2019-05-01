/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 14:01:10 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c && ./a.out
int main (void)
{
int a[1] = {1};

printf("%8.10p\n", 0);
ft_printf("%8.10p\n", 0);

{
	ft_putchar(162);

	// double f = 0.0000022321555;
	//ft_printf("%15.4d\n", -424242);
	//ft_printf("%lld\n", -9223372036854775808);
	return (0);
}
