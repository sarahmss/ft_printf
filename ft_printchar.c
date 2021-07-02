/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:27:58 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/02 09:20:29 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_printchar(t_format *tab)
{
	tab->ch = 1;
	if (tab->l_just == 0)
	{
		ft_flags(tab);
		tab->printed += ft_putchar_fd(va_arg(tab->args, int), 1);
	}
	else if (tab->l_just == 1)
	{
		tab->printed += ft_putchar_fd(va_arg(tab->args, int), 1);
		ft_flags(tab);
	}
	tab->ch = 0;
}
