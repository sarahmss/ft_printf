/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:50:49 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/15 09:56:13 by smodesto         ###   ########.fr       */
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
	if ((tab->pad_zero == 1) || ((tab->precision > 0) && (tab->in || tab->hex)))
		ft_padzero(tab);
	print = tab->printed;
	ft_initialise_tab(tab);
	tab->precision = prec;
	tab->printed = print;
}

static int	ft_findsize3(t_format *tab, int i)
{
	if ((tab->hex) && (tab->precision > (tab->hex - 1)) && (tab->num < 0))
		i = i - (tab->precision + 1);
	else if ((tab->hex) && (tab->precision > tab->hex) && (tab->num >= 0))
		i = i - tab->precision;
	else if ((tab->hex > 0) && (tab->precision == -1) && (tab->num == 0))
		return (i);
	else if (tab->hex > 0)
		i = i - tab->hex;
	return (i);
}

int	ft_findsize1(t_format *tab, int i)
{
	if ((tab->precision > 0) && (tab->str > tab->precision)
		&& (tab->precision != -1))
		i = i - tab->precision;
	else if ((tab->str > 0) && (tab->precision != -1))
		i = i - tab->str;
	if ((tab->in) && (tab->precision > (tab->in - 1)) && (tab->num < 0))
		i = i - (tab->precision + 1);
	else if ((tab->in) && (tab->precision > tab->in) && (tab->num >= 0))
		i = i - tab->precision;
	else if ((tab->in > 0) && (tab->precision == -1) && tab->num == 0)
		return (i);
	else if (tab->in > 0)
		i = i - tab->in;
	if ((tab->ch > 0))
		i = i - tab->ch;
	i = ft_findsize3(tab, i);
	return (i);
}

int	ft_findsize(t_format *tab, char *stemp, int i)
{
	char	width[10];

	ft_bzero(width, 10);
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
	i = ft_findsize1(tab, i);
	return (i);
}
