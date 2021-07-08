/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:50:49 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/08 08:15:00 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_flags(t_format *tab)
{
	int	prec;
	int	print;

	prec = tab->precision;
	if ((tab->width == 1 || tab->width_prm[1] != 0) && (tab->pad_zero == 0))
		ft_width(tab);
	if (tab->pad_zero == 1 && tab->l_just == 0)
		ft_padzero(tab);
	print = tab->printed;
	ft_initialise_tab(tab);
	tab->precision = prec;
	tab->printed = print;
}

static int	ft_sup(t_format *tab, char *stemp, int i)
{
	char	width[10];

	if (tab->width_prm[1] != 0)
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
	if (tab->str > 0)
		i = i - tab->str;
	if (tab->ch > 0)
		i = i - tab->ch;
	if (tab->in > 0)
		i = i - tab->in;
	if (tab->hex > 0)
		i = i - tab->hex;
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

int	ft_prm(t_format *tab, char *stemp)
{
	stemp++;
	if(*stemp == '.')
		tab->width_prm[0] = va_arg(tab->args, int);
	else
		tab->width_prm[1] = va_arg(tab->args, int);
	if (tab->width_prm[1] < 0)
	{
		tab->l_just = 1;
		tab->width_prm[0] *= -1;
	}
	return (0);
}
