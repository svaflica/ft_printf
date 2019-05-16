/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/16 15:49:06 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c ./src/ft_buf/*.c  src/ft_lnum/*.c && ./a.out

// void		ft_print_bits2(__int128_t b, size_t me, size_t size)
// {
// 	if (me < size)
// 	{
// 		ft_print_bits2(b >> 1, me + 1, size);
// 		printf("%d", b & 1);
// 	}
// }

// void		ft_print_bits(double b, size_t size)
// {
// 	int j;

// 	j = 0;
// 	__int128_t a = *(__int128_t *)&b;
// 	ft_print_bits2(a, 0, size);
// 	printf("\n");
// }

// int main (void)
// {
// 	// setlocale(LC_ALL, "ru_RU.UTF-4");

// 	double f = 3.2;

// 	printf("NY: %#-0 +30.f\n", f);
// 	ft_printf("NY: %#-0 +30.f\n", f);
// }

int main(void)
{
	printf("{%+f}{%+F}\n", -1.42, -1.42);
	ft_printf("{%+f}{%+F}\n", -1.42, -1.42);

}
