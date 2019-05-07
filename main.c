/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/07 15:28:16 by djeanna          ###   ########.fr       */
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
	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("%d\n\n", printf("%C\n", L'ÁM-^L´'));
	printf("%d\n\n", ft_printf("%C\n", L'ÁM-^L´'));
}
