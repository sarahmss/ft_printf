/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:02:01 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/13 11:54:30 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	checkint(t_format *tab, int i, char *stemp)
{
	if (tab->num < 0)
			tab->printed += ft_putchar_fd('-', 1);
	if ((tab->precision > 0) && (tab->num >= 0))
		i = tab->precision - tab->in;
	else if ((tab->precision > 0) && (tab->num < 0))
		i = tab->precision - tab->in + 1;
	else
		i = ft_findsize(tab, stemp, i);
	return (i);
}

static int	checkhex(t_format *tab, int i, char *stemp)
{
	if (tab->num < 0)
			tab->printed += ft_putchar_fd('-', 1);
	if ((tab->precision > 0) && (tab->num >= 0))
		i = tab->precision - tab->hex;
	else if ((tab->precision > 0) && (tab->num < 0))
		i = tab->precision - tab->hex + 1;
	else
		i = ft_findsize(tab, stemp, i);
	return (i);
}

void	ft_padzero(t_format *tab)
{
	int		i;
	char	*stemp;

	stemp = tab->temp;
	i = 0;
	stemp++;
	if (tab->in)
		i = checkint(tab, i, stemp);
	if (tab->hex)
		i = checkhex(tab, i, stemp);
	while (i-- > 0)
		tab->printed += ft_putchar_fd('0', 1);
}
