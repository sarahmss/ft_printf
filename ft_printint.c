/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:26:48 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/12 13:29:00 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	ft_li_flags(t_format *tab, int i)
{
	int	prec;
	int	print;

	prec = tab->precision;
	if (((i == 0) && ((tab->pad_zero == 1) || (tab->precision > tab->in))))
		ft_padzero(tab);
	if (i == 0)
		return (1);
	if ((tab->width == 1 || tab->width_prm[0] != 0))
		ft_width(tab);
	print = tab->printed;
	ft_initialise_tab(tab);
	tab->precision = prec;
	tab->printed = print;
	return (0);
}

static long	ft_intsup(t_format *tab, char *temp)
{
	long	num;

	num = va_arg(tab->args, int);
	tab->ch = num;
	tab->in = ft_intlen(num);
	if (*temp == 'u')
		{
			num *= -1;
			tab->ch = num;
		}
	else if ((num < 0) && ((tab->precision > (tab->in - 1)) || tab->pad_zero))
		num *= -1;
	return (num);
}

void	ft_printint(char *temp, t_format *tab)
{
	long	num;
	int		i;

	i = 0;
	num = ft_intsup(tab, temp);
	if (tab->l_just == 0)
	{
		ft_flags(tab);
		if (*temp == 'u')
			tab->printed += ft_putnbruns_fd(num, 1);
		else
			tab->printed += ft_putnbr_fd(num, 1);
	}
	if (tab->l_just == 1)
	{
		i = ft_li_flags(tab, i);
		if (*temp == 'u')
			tab->printed += ft_putnbruns_fd(num, 1);
		else
			tab->printed += ft_putnbr_fd(num, 1);
		if (i == 1)
			i = ft_li_flags(tab, i);
	}
	tab->precision = 0;
}
