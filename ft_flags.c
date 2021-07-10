/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:50:49 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/10 18:13:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_flags(t_format *tab)
{
	int	prec;
	int	print;

	prec = tab->precision;
	if ((tab->width == 1 || tab->width_prm[0] != 0) && (tab->pad_zero == 0))
		ft_width(tab);
	if (tab->pad_zero == 1 && tab->l_just == 0)
		ft_padzero(tab);
	print = tab->printed;
	ft_initialise_tab(tab);
	tab->precision = prec;
	tab->printed = print;
}

int	ft_widthparam(t_format *tab, char *stemp)
{
	tab->width_prm[0] = va_arg(tab->args, int);
	if (tab->width_prm[0] < 0)
	{
		tab->l_just = 1;
		tab->width_prm[0] *= -1;
	}
	tab->width_prm[1] = 0;
	stemp++;
	return (0);
}
