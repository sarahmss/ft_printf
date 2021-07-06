/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:41:53 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/06 10:11:11 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/*see what we have between % and the specifier, setting the flags
 temp = pointer to %, tab == t_format to set*/

t_format	*ft_initialise_tab(t_format *tab)
{
	tab->temp = NULL;
	tab->width = 0;
	tab->precision = 0;
	tab->l_just = 0;
	tab->pad_zero = 0;
	tab->width_prm[0] = 0;
	tab->width_prm[1] = -1;
	tab->printed = 0;
	tab->str = 0;
	tab->ch = 0;
	tab->in = 0;
	tab->hex = 0;
	return (tab);
}

static int	ft_eval_sup(char *temp, t_format *tab)
{
	if (*temp == 's')
		ft_printstr(tab);
	if (*temp == 'c')
		ft_printchar(tab);
	if (*temp == '%')
		tab->printed += ft_putchar_fd('%', 1);
	if (*temp == 'i')
		ft_printint(temp, tab);
	if (*temp == 'd')
		ft_printint(temp, tab);
	if (*temp == 'u')
		ft_printint(temp, tab);
	if ((*temp == 'p') || (*temp == 'X') || (*temp == 'x'))
		ft_printhex(temp, tab);
	temp++;
	tab->temp = temp;
	return (0);
}

char	*ft_eval_format(char *temp, t_format *tab)
{
	tab->temp = temp;
	temp++;
	while (*temp != 's' && *temp != 'c' && *temp != '%'
		&& *temp != 'd' && *temp != 'i' && *temp != 'u'
		&& *temp != 'p' && *temp != 'x' && *temp != 'X')
	{
		if ((*temp == '*') && (tab->width_prm[1] == -1))
		{
			tab->width_prm[0] = va_arg(tab->args, int);
			if (ft_strchr(temp, '*'))
				tab->width_prm[1] = 0;
		}
		if (*temp == '0' && tab->width == 0 && tab->l_just == 0)
			tab->pad_zero = 1;
		if (ft_isdigit(*temp) && tab->precision == 0 && tab->pad_zero == 0)
			tab->width = 1;
		if (*temp == '.')
			tab->precision = ft_precision(tab);
		if (*temp == '-')
			tab->l_just = 1;
		temp++;
	}
	ft_eval_sup(temp, tab);
	return (tab->temp);
}
