/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:27:58 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/15 15:51:59 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_printchar(t_format *tab, char *temp)
{
	char	c;

	tab->ch = 1;
	if (*temp == '%')
		c = '%';
	else
		c = va_arg(tab->args, int);
	if (tab->l_just == 0)
	{
		ft_flags(tab);
		tab->printed += ft_putchar_fd(c, 1);
	}
	else if (tab->l_just == 1)
	{
		tab->printed += ft_putchar_fd(c, 1);
		ft_flags(tab);
	}
	tab->ch = 0;
}
