/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/09 14:47:03 by qclubfoo         ###   ########.fr       */
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

	// test->debug = 1;
	// printf("{010}%2s", "str");
	// char c;
	// char buf[30] = "\033[38;5;0m";
	// printf("\033[38;5;153mBoooooooooold greeeeeeeen\033[0mAAAAAAAAA\n");
	// write(1, "\033[38;5;0m", 11);
	// write(1, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n", 16);
	// write(1, "\033[0m", 4);
	printf("{%f}{%F}\n", 1.42, 1.42);
	ft_printf("{%f}{%F}", 1.42, 1.42);
	
}
