/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:25:57 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/09 10:18:41 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_sup2(t_format *tab, int i)
{
	if (tab->precision != -1)
	{
		if (tab->precision > 0 && tab->str > tab->precision)
			i = i - tab->precision;
		else if (tab->str > 0)
			i = i - tab->str;
		if (tab->ch > 0)
			i = i - tab->ch;
		if (tab->in > 0)
			i = i - tab->in;
		if (tab->hex > 0)
			i = i - tab->hex;
	}
	return (i);
}

static int	ft_sup(t_format *tab, char *stemp, int i)
{
	char	width[10];

	if (tab->width_prm[0] > 0)
		i = tab->width_prm[0];
	else
	{
		while (ft_isdigit(*stemp) || *stemp == '-')
		{
			if (ft_isdigit(*stemp))
				width[i++] = *stemp;
			stemp++;
		}
		i = ft_atoi(width);
	}
	i = ft_sup2(tab, i);
	return (i);
}

void	ft_width(t_format *tab)
{
	int		i;
	char	*stemp;

	stemp = tab->temp;
	i = 0;
	stemp++;
	i = ft_sup(tab, stemp, i);
	while (i-- > 0)
		tab->printed += ft_putchar_fd(' ', 1);
}

void	ft_padzero(t_format *tab)
{
	int		i;
	char	*stemp;

	stemp = tab->temp;
	i = 0;
	stemp++;
	i = ft_sup(tab, stemp, i);
	if ((tab->in && tab->ch < 0))
		tab->printed += ft_putchar_fd('-', 1);
	while (i-- > 0)
		tab->printed += ft_putchar_fd('0', 1);
}