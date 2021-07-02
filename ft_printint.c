/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:26:48 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/02 09:53:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_printint(char *temp, t_format *tab)
{
	long	num;

	num = va_arg(tab->args, int);
	tab->in = ft_intlen(num);
	tab->ch = num;
	if (num < 0 && tab->pad_zero == 1 )
		num *= -1;
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
		if (*temp == 'u')
			tab->printed += ft_putnbruns_fd(num, 1);
		else
			tab->printed += ft_putnbr_fd(num, 1);
		ft_flags(tab);
	}
	tab->precision = 0;
}
