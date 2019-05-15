/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/15 15:36:47 by qclubfoo         ###   ########.fr       */
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
	setlocale (LC_ALL, "");
	// printf("{%03.2d}\n", 2);
	// ft_printf("{%03.2d}\n", 2);

	printf(">------------<%36lc>------------<", (char)128150);
	ft_printf(">------------<%36lc>------------<", (char)128150);

	// printf("%.4x\n", 42);
	// ft_printf("%.4x\n", 42);

	// printf("!%11.2zx!\n", 0);
	// ft_printf("!%11.2zx!\n", 0);

	// printf("^.^/%11.2jx^.^/\n", 0);
	// ft_printf("^.^/%11.2jx^.^/\n", 0);
	
	// printf("!%#049hx!\n", 0);
	// ft_printf("!%#049hx!\n", 0);

	// printf("%#017hhx\n", 0);
	// ft_printf("%#017hhx\n", 0);
	
	// printf("\\!/%0#.35jx\\!/\n", 0);
	// ft_printf("\\!/%0#.35jx\\!/\n", 0);

	// printf("%#.1x\n", 0);
	// ft_printf("%#.1x\n", 0);

	// printf(">------------<%#2llx>------------<\n", 0);
	// ft_printf(">------------<%#2llx>------------<\n", 0);
	
	// printf("^.^/%#13.11zx^.^/\n", 0);
	// ft_printf("^.^/%#13.11zx^.^/\n", 0);

	// printf("%#016.35hhx\n", 0);
	// ft_printf("%#016.35hhx\n", 0);

	// printf("^.^/%016.28jx^.^/\n", 0);
	// ft_printf("^.^/%016.28jx^.^/\n", 0);

	// printf("%2llx\n", 0);
	// ft_printf("%2llx\n", 0);

	// printf("42%-32jx42\n", 0);
	// ft_printf("42%-32jx42\n", 0);

	// printf("%hhx\n", 0);
	// ft_printf("%hhx\n", 0);

	// printf("\\!/%#49.48zx\\!/\n", 0);
	// ft_printf("\\!/%#49.48zx\\!/\n", 0);
	// printf(">------------<%2zo>------------<\n", 0);
	// ft_printf(">------------<%2zo>------------<\n", 0);
	
}
