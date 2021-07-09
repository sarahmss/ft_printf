/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:58:39 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/09 10:35:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_printstr(t_format *tab)
{
	char	*stemp;

	stemp = va_arg(tab->args, char *);
	tab->str = ft_strlen(stemp);
	if (stemp == NULL)
		ft_flags(tab);
	else if (tab->l_just == 0)
	{
		ft_flags(tab);
		tab->printed += ft_putnstr_fd(stemp, 1, tab->precision);
	}
	else if (tab->l_just == 1)
	{
		tab->printed += ft_putnstr_fd(stemp, 1, tab->precision);
		ft_flags(tab);
	}
	tab->precision = 0;
}
