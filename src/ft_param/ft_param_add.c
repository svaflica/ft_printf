/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:52:35 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/25 11:20:47 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		ft_skip_num(char **str)
{
	while (**str && **str >= '0' && **str <= '9')
		*str += 1;
}

static void		ft_get_length(char **str, t_param *new)
{
	if (**str == 'L' || **str == 'l' || **str == 'h')
	{
		new->length += **str;
		*str += 1;
	}
	if ((new->length == 'l' && **str == 'l') ||
		(new->length == 'h' && **str == 'h'))
	{
		new->length += **str;
		*str += 1;
	}
}

static void		ft_flags(t_param *new, char **str)
{
	while (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
	{
		(**str == '#') ? new->hasht = 1 : 0;
		(**str == '0') ? new->zero = 1 : 0;
		(**str == '-') ? new->minus = 1 : 0;
		(**str == '+') ? new->plus = 1 : 0;
		(**str == ' ') ? new->space = 1 : 0;
		*str += 1;
	}
	(new->space == 1 && new->plus == 1) ? new->space = 0 : 1;
	(new->zero == 1 && new->minus == 1) ? new->zero = 0 : 1;
}

int			ft_param_add(t_param *new, char **str)
{
	ft_flags(new, str);
	new->width = ft_atoi(*str);
	ft_skip_num(str);
	if (**str == '.')
	{
		if (*(*str + 1) >= '0' && *(*str + 1) <= '9')
			new->precision = ft_atoi(*str + 1);
		else if (*(*str + 1) == '\0')
			return (-1);
		else
			new->precision = 0;
		*str += 1;
		ft_skip_num(str);
	}
	ft_get_length(str, new);
	return (1);
}
