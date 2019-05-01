/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 16:18:43 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c && ./a.out
int main (void)
{
	// int a = -9999;
	// char *str;

	// printf("%x\n", a);
	// ft_printf("%x\n", a);

	// printf("-->%x<--\n", -9999);
	// printf("-->%-020x<--\n", -9999);
	// printf("-->%#x<--\n", -9999);
	// printf("-->%-x<--\n", -9999);
	// printf("-->%#-30.20x<--\n", -9999);
	// printf("-->%015x<--\n", -9999);
	// printf("-->%015.x<--\n", -9999);
	// ft_printf("-->%#10x<--\n", 0);
	printf("%#.x\n", 0);
	ft_printf("%.x\n", 0);
	// ft_printf("-->%#010x<--\n", 0);
	// printf("-->%-10x<--\n", -9999);
	// printf("-->%10x<--\n", -9999);


}
