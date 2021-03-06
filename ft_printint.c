/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:26:48 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/15 10:59:52 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	ft_li_flags(t_format *tab, int i)
{
	int	prec;
	int	print;

	prec = tab->precision;
	if (((i == 0) && ((tab->pad_zero == 1)
				|| (tab->precision > tab->in && tab->num >= 0)
				|| (tab->precision >= (tab->in - 1) && tab->num < 0))))
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

static long	ft_catnbr(t_format *tab, char *temp)
{
	long int	num;

	num = 0;
	if ((tab->precision) || (tab->l_just))
		tab->pad_zero = 0;
	if (*temp == 'u')
		num = va_arg(tab->args, unsigned int);
	else
		num = va_arg(tab->args, int);
	tab->num = num;
	tab->in = ft_intlen(num);
	if ((num < 0) && ((tab->precision >= (tab->in - 1)) || tab->pad_zero))
		num *= -1;
	return (num);
}

static int	ft_without_left_just(t_format *tab, char *temp, long int num, int i)
{
	ft_flags(tab);
	if ((num == 0) && (tab->precision == -1))
		i = 1;
	else if (*temp == 'u')
		tab->printed += ft_putnbruns_fd(num, 1);
	else
		tab->printed += ft_putnbr_fd(num, 1);
	return (i);
}

int	ft_printint(char *temp, t_format *tab)
{
	long int	num;
	int			i;

	i = 0;
	num = ft_catnbr(tab, temp);
	if (tab->l_just == 0)
		i = ft_without_left_just(tab, temp, num, i);
	if (tab->l_just == 1)
	{
		i = ft_li_flags(tab, i);
		if ((num == 0) && (tab->precision == -1))
			i = 1;
		else if (*temp == 'u')
			tab->printed += ft_putnbruns_fd(num, 1);
		else
			tab->printed += ft_putnbr_fd(num, 1);
		if (i == 1)
			i = ft_li_flags(tab, i);
	}
	tab->precision = 0;
	return (0);
}
