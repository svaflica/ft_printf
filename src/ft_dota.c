/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 23:36:04 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/16 17:34:10 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_prec(int shift, unsigned long long m, int prec)
{
	t_lnum		fi;
	t_lnum		res;
	char		*res_c;
	char		*tmp;
	int			tmp_shift;

	ft_lnum_new(&fi);
	ft_lnum_new(&res);
	ft_lnum_plus2(&res, 1);
	ft_lnum_plus2(&fi, 1);
	tmp_shift = shift;
	while (shift > 0)
	{
		if ((m >> shift--) & 1)
			ft_lnum_plus(&res, fi);
		ft_lnum_mul(&res, 10);
		ft_lnum_mul(&fi, 5);
	}
	res_c = NULL;
	while (--res.size >= 0)
	{
		tmp = ft_itoa(res.ar[res.size]);
		res_c = ft_strjoin(res_c, tmp);
	}
	return (res_c);
}

static int		ft_round2(char **prec_c, int prec, int carry)
{
	if (carry == 1)
		prec--;
	while (prec >= 0 && carry > 0)
		if (((*prec_c)[prec--] += carry) > '9')
		{
			carry = 1;
			(*prec_c)[prec + 1] = '0';
		}
		else
			carry = 0;
	return (carry > 0);
}

static void		ft_round(char **main, char **prec_c, int prec)
{
	int		carry;
	char	*tmp;

	if ((*prec_c)[prec] >= '5')
	{
		if (ft_round2(prec_c, prec, 5))
			if (ft_round2(main, ft_strlen(*main), 1))
			{
				tmp = *main;
				*main = ft_strjoin("1", tmp);
				free(tmp);
			}
	}
	/* else
	{ */
		tmp = *prec_c;
		*prec_c = ft_strndup(tmp, prec);
		free(tmp);
/* 	} */
}

static char		*ft_glue(int s, long long e, unsigned long long m, int prec)
{
	int						tmp;
	char					*tmp_prec;
	char					*tmp_c;
	char					*main;
	char					*prec_c;

	if (/* e >= 64 ||  */e <= 0)
		main = ft_itoa(0);
	else
		main = ft_itoa(m >> (64 - e));
	prec_c = ft_prec(64 - e, m, prec);
	if ((tmp = ft_strlen(prec_c)) > prec)
		ft_round(&main, &prec_c, prec);
	else if (tmp < prec)
	{
		tmp_c = ft_memnew(prec - tmp, '0');
		tmp_prec = prec_c;
		prec_c = ft_strjoin(tmp_prec, tmp_c);
		free(tmp_prec);
		free(tmp_c);
	}
	if (prec != 0)
	{
		if (s == 1)
		{
			tmp_c = main;
			main = ft_strjoin("-", main);
			free(tmp_c);
		}
		tmp_c = main;
		main = ft_strjoin(main, ".");
		free(tmp_c);
		tmp_c = main;
		main = ft_strjoin(main, prec_c);
		free(tmp_c);
	}
	return (main);
}

char		*ft_dota(long double f, int precision)
{
	int								s;
	long long						e;
	unsigned long long				m;

	s = ((*(__int128_t *)&f) >> 79) & 1;
	e = (((*(__int128_t *)&f) >> 64) & 0x7FFF) - 16383 + 1;
	m = (*(__int128_t *)&f) & 0xFFFFFFFFFFFFFFFF;
	if (e == 16385 && s == 0 && m == 13835058055282163712)
		return (ft_strndup("nan", 3));
	if (e == 16385)
		return (s == 1 ? ft_strndup("-inf", 4) : ft_strndup("inf", 3));
	return (ft_glue(s, e, m, precision));
}
