/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 08:39:30 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/24 16:17:17 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 922337203685477580

typedef struct		s_param
{
	char			flags[5];
	int				width;
	int				subtl;
}					t_param;

t_param				*ft_param_new(void);
void				ft_param_add(t_param *new, char **str);
void				ft_param_nul(t_param *param);

void				ft_printf(char *str, ...);

char				*ft_percent(va_list ap, char *str, t_param *list);

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);

char				*ft_strchr(const char *s, int c);

int					ft_atoi(const char *str);
char				*ft_itoa(int n);

#endif
