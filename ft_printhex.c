/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:23:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/12 18:18:29 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	ft_lhex_flags(t_format *tab, int i)
{
	int	prec;
	int	print;

	prec = tab->precision;
	if (((i == 0) && ((tab->pad_zero == 1) || (tab->precision > tab->hex))))
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

static char	*ft_sup(char *temp, t_format *tab)
{
	char	*stemp;

	stemp = NULL;
	tab->num = va_arg(tab->args, unsigned int);
	if (*temp == 'X')
		stemp = ft_itoa_bases(tab->num, 16, 'X');
	else if (*temp == 'x')
		stemp = ft_itoa_bases(tab->num, 16, 'x');
	else if (*temp == 'p')
		stemp = ft_itoa_bases(tab->num, 16, 'x');
	tab->hex = ft_strlen(stemp);
	return (stemp);
}

void	ft_printhex(char *temp, t_format *tab)
{
	char	*stemp;
	int		i;

	i = 0;
	stemp = ft_sup(temp, tab);
	if (tab->l_just == 0)
	{
		if (*temp == 'p')
			tab->hex += 2;
		ft_flags(tab);
		if (*temp == 'p')
			tab->printed += ft_putstr_fd("0x", 1);
		tab->printed += ft_putstr_fd(stemp, 1);
	}
	if (tab->l_just == 1)
	{
		i = ft_lhex_flags(tab, i);
		if (*temp == 'p')
		{
			tab->hex += 2;
			tab->printed += ft_putstr_fd("0x", 1);
		}
		tab->printed += ft_putstr_fd(stemp, 1);
		if (i == 1)
			i = ft_lhex_flags(tab, i);
	}
	free(stemp);
}
