/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:02:01 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/13 11:45:32 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_padzero(t_format *tab)
{
	int		i;
	char	*stemp;

	stemp = tab->temp;
	i = 0;
	stemp++;
	if (((tab->in) && (tab->num < 0)))
		tab->printed += ft_putchar_fd('-', 1);
	if ((tab->precision > 0) && (tab->num >= 0) && (tab->in))
		i = tab->precision - tab->in;
	else if ((tab->precision > 0) && (tab->num < 0) && (tab->in))
		i = tab->precision - tab->in + 1;
	if ((tab->precision > 0) && (tab->num >= 0) && (tab->hex))
		i = tab->precision - tab->hex;
	else if ((tab->precision > 0) && (tab->num < 0) && (tab->hex))
		i = tab->precision - tab->hex + 1;
	else
		i = ft_findsize(tab, stemp, i);
	while (i-- > 0)
		tab->printed += ft_putchar_fd('0', 1);
}
