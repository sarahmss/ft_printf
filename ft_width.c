/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:25:57 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/13 09:22:49 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_widthparam(t_format *tab, char *stemp)
{
	tab->width_prm[0] = va_arg(tab->args, int);
	if (tab->width_prm[0] < 0)
	{
		tab->l_just = 1;
		tab->width_prm[0] *= -1;
	}
	tab->width_prm[1] = 0;
	stemp++;
	return (0);
}

void	ft_width(t_format *tab)
{
	int		i;
	char	*stemp;

	stemp = tab->temp;
	i = 0;
	stemp++;
	i = ft_findsize(tab, stemp, i);
	while (i-- > 0)
		tab->printed += ft_putchar_fd(' ', 1);
}
