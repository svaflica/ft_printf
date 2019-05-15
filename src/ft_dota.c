/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 23:36:04 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/15 18:25:43 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_print_bits2(__int128_t b, size_t me, size_t size)
{
	if (me < size)
	{
		ft_print_bits2(b >> 1, me + 1, size);
		printf("%d", b & 1);
	}
}

static void		ft_print_bits(long double b, size_t size)
{
	int j;

	j = 0;
	__int128_t a = *(__int128_t *)&b;
	ft_print_bits2(a, 0, size);
	printf("\n");
}

static void		ft_print_bits3(__int64_t b, size_t me, size_t size)
{
	if (me < size)
	{
		ft_print_bits2(b >> 1, me + 1, size);
		printf("%d", b & 1);
	}
}

// void		ft_prec(unsigned long long m, int shift)
// {
// 	t_lnum fi;
// 	t_lnum res;

// 	ft_lnum_new(&fi);
// 	ft_lnum_new(&res);
// 	ft_lnum_plus2(&fi, 1);
// 	while (shift)
// 	{
// 		if ((m >> shift--) & 1)
// 		{
// 			ft_lnum_plus(&res, fi);
// 		}
// 		ft_lnum_mul(&res, 10);
// 		ft_lnum_mul(&fi, 5);
// 	}
// 	printf("\n\n");
// 	for (int i = res.size; i >= 0; --i)
// 	{
// 		printf("%09d ",res.ar[i]);
// 	}
// }

static char		*ft_prec(t_double_cast	d, char *main, int shift)
{
	t_lnum fi;
	t_lnum res;

	ft_lnum_new(&fi);
	ft_lnum_new(&res);
	ft_lnum_plus2(&fi, 1);
	while (shift)
	{
		if ((d.cast.m >> shift--) & 1)
			ft_lnum_plus(&res, fi);
		ft_lnum_mul(&res, 10);
		ft_lnum_mul(&fi, 5);
	}
	printf("\n");
	for (int i = res.size; i >= 0; --i)
		printf("%09d ", res.ar[i]);
	free(main);
}

char		*ft_dota(long double f, int precision)
{
	// int								s;
	// int								e;
	// unsigned long long				m;
	// unsigned long long				d;
	// int								shift;

	// s = ((*(__int128_t *)&f) >> 79) & 1;
	// e = (((*(__int128_t *)&f) >> 64) & 0x7FFF) - 16383 + 1;
	// m = (*(__int128_t *)&f) & 0xFFFFFFFFFFFFFFFF;
	// shift = 64 - e;
	// d = m >> shift;

	// me.f = f;
	// ft_print_bits(f, 80);
	// printf("\nsign: ");
	// ft_print_bits3(s, 0, 1);
	// printf("\nexpo: %llu    ", e);
	// ft_print_bits3(e, 0, 15);
	// printf("\nmant:    ");
	// ft_print_bits3(m, 0, 64);
	// printf("\n%d\n\n", d);
	// ft_prec(m, shift);
	// printf("\n\nVERY USEFUL LALALALA\n\n");

	int				shift;
	t_double_cast	d;

	d.cast.e = d.cast.e - 16383 + 1;
	shift = 64 - d.cast.e;
	ft_print_bits(d.f, 80);
	printf("\nsign: ");
	ft_print_bits3(d.cast.s, 0, 1);
	printf("\nexpo: %llu    ", d.cast.e);
	ft_print_bits3(d.cast.e, 0, 15);
	printf("\nmant:    ");
	ft_print_bits3(d.cast.m, 0, 64);
	printf("\n%d\n\n", d);
	ft_prec(d, ft_itoa_base_ll(d.cast.m >> shift, 10), shift);
	return (NULL);
}


// static char		*ft_prec(unsigned long long m, char *main, int shift)
// {
// 	t_lnum fi;
// 	t_lnum res;

// 	ft_lnum_new(&fi);
// 	ft_lnum_new(&res);
// 	ft_lnum_plus2(&fi, 1);
// 	while (shift)
// 	{
// 		if ((m >> shift--) & 1)
// 			ft_lnum_plus(&res, fi);
// 		ft_lnum_mul(&res, 10);
// 		ft_lnum_mul(&fi, 5);
// 	}
// 	printf("\n");
// 	for (int i = res.size; i >= 0; --i)
// 	{
// 		printf("%09d ",res.ar[i]);
// 	}
// 	free(main);
// }

// static char		*ft_glue(t_double_cast d, int prec)
// {
// 	int		shift;

// 	shift = 64 - (d.cast.e > 64 ? 0 : d.cast.e);
// 	return (ft_prec(d.cast.m,
// 		ft_itoa_base_ll(shift >= 64 ? 0 : d.cast.m >> shift, 10), shift));
// }

// char		*ft_dota(long double f, int prec)
// {
// 	t_double_cast d;

// 	d.f = f;
// 	d.cast.e = d.cast.e - 16383 + 1;

// 	ft_print_bits(d.f, 80);
// 	printf("\nsign: ");
// 	ft_print_bits3(d.cast.s, 0, 1);
// 	printf("\nexpo: %llu    ", d.cast.e);
// 	ft_print_bits3(d.cast.e, 0, 15);
// 	printf("\nmant:    ");
// 	ft_print_bits3(d.cast.m, 0, 64);

// 	return (ft_glue(d, prec));
// }
