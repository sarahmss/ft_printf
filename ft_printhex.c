/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:23:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/15 10:42:42 by smodesto         ###   ########.fr       */
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

static char	*ft_catstr(char *temp, t_format *tab)
{
	char					*stemp;

	stemp = NULL;
	if ((tab->precision) || (tab->l_just))
		tab->pad_zero = 0;
	if (*temp == 'p')
	{
		tab->nump = va_arg(tab->args, unsigned long int);
		tab->hex += 2;
	}
	else
		tab->num = va_arg(tab->args, unsigned int);
	if (*temp == 'X')
		stemp = ft_itoa_bases(tab->num, 16, 'X');
	else if (*temp == 'x')
		stemp = ft_itoa_bases(tab->num, 16, 'x');
	else if (tab->nump == ULLONG_MAX)
		stemp = ft_strdup("ffffffffffffffff");
	else if (*temp == 'p')
		stemp = ft_itoa_bases(tab->nump, 16, 'x');
	tab->hex += ft_strlen(stemp);
	return (stemp);
}

static int	ft_without_left_just(char *temp, t_format *tab, char *stemp, int i)
{
	ft_flags(tab);
	if ((*stemp == '0') && (tab->precision == -1))
		i = 1;
	else if (*temp == 'p')
		tab->printed += ft_printf("0x%s", stemp);
	else if (stemp)
		tab->printed += ft_putstr_fd(stemp, 1);
	return (i);
}

void	ft_printhex(char *temp, t_format *tab)
{
	char	*stemp;
	int		i;

	i = 0;
	stemp = ft_catstr(temp, tab);
	if (tab->l_just == 0)
		i = ft_without_left_just(temp, tab, stemp, i);
	if (tab->l_just == 1)
	{
		i = ft_lhex_flags(tab, i);
		if ((*stemp == '0') && (tab->precision == -1))
			i = 1;
		else if (*temp == 'p')
			tab->printed += ft_printf("0x%s", stemp);
		else if (stemp)
			tab->printed += ft_putstr_fd(stemp, 1);
		if (i == 1)
			i = ft_lhex_flags(tab, i);
	}
	free(stemp);
	tab->precision = 0;
}
