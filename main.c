/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/13 15:55:27 by qclubfoo         ###   ########.fr       */
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
	// printf("{%03.2d}\n", 2);
	// ft_printf("{%03.2d}\n", 2);
	printf("^.^/%043.14zo^.^/\n", 0);
	ft_printf("^.^/%043.14zo^.^/\n", 0);
	
	// printf(">------------<%2zo>------------<\n", 0);
	// ft_printf(">------------<%2zo>------------<\n", 0);
	
}
