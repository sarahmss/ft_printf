/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:41:53 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/12 11:40:23 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

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
	if ((*temp == 'i') || (*temp == 'd'))
	{
		if ((tab->precision) || (tab->l_just))
			tab->pad_zero = 0;
		ft_printint(temp, tab);
	}
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
		if ((*temp == '*') && (tab->width_prm[1] == -1)
			&& (tab->precision != -2))
			ft_widthparam(tab, temp);
		if ((*temp == '0') && (tab->width == 0) && (tab->l_just == 0)
			&& (tab->precision != -1))
			tab->pad_zero = 1;
		if (ft_isdigit(*temp) && tab->precision == 0 && *temp != '0')
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
