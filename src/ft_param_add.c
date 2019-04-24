/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:52:35 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/24 16:23:35 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_skip_num(char **str)
{
	while (**str && **str >= '0' && **str <= '9')
		*str += 1;
}

void			ft_param_add(t_param *new, char **str)
{
	int		iter;

	iter = 0;
	while (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
	{
		if (!(ft_strchr(new->flags, (int)**str)))
			new->flags[iter++] = **str;
		*str += 1;
	}
	new->width = ft_atoi(*str);
	ft_skip_num(str);
	if (**str == '.')
	{
		if (*(*str + 1) >= '0' && *(*str + 1) <= '9')
			new->subtl = ft_atoi(*str + 1);
		else if (*(*str + 1) == '\0')
			exit(-1);
		else
			new->subtl = 0;
		*str += 1;
		ft_skip_num(str);
	}
}
