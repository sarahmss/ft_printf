/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:23:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/02 10:12:43 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static char	*ft_sup(char *temp, t_format *tab)
{
	char	*stemp;

	if (*temp == 'X')
		stemp = ft_itoa_bases(va_arg(tab->args, unsigned int), 16, 'X');
	else if (*temp == 'x')
		stemp = ft_itoa_bases(va_arg(tab->args, unsigned int), 16, 'x');
	else if (*temp == 'p')
		stemp = ft_itoa_bases(va_arg(tab->args, unsigned int), 16, 'x');
	tab->hex = ft_strlen(stemp);
	return (stemp);
}

void	ft_printhex(char *temp, t_format *tab)
{
	char	*stemp;

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
		if (*temp == 'p')
		{
			tab->hex += 2;
			tab->printed += ft_putstr_fd("0x", 1);
		}
		tab->printed += ft_putstr_fd(stemp, 1);
		ft_flags(tab);
	}
}
