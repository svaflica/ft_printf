/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/12 14:23:52 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c ./src/ft_buf/*.c && ./a.out
int main (void)
{
	int i;

	setlocale(LC_ALL, "ru_RU.UTF-4");

int i = 3018;
	long double n = 2;
__int128_t  exp        = (*(__int128_t *)&n & 3018); /* i.e 1023 */
__int128_t mantissa   = *(__int128_t *)&n & 0xFFFFFFFFFFFFFFFF;
//printf("%jd\n\n", exp);
ft_printf("%d\n", 500);
}
