/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 11:06:36 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c && ./a.out

int main(void)

{
	int a[3] = {1, 2, 3};
	// double f = 0.0000022321555;
	printf("%d\n\n\n\n\n", printf("%p\n", &a[1]));
	printf("%d\n\n\n\n\n", ft_printf("%p\n", &a[1]));
	//ft_printf("%15.4d\n", -424242);
	//ft_printf("%lld\n", -9223372036854775808);
	return (0);
}
