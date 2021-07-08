/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:24:29 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/08 09:52:36 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_precision(t_format *tab)
{
	int		i;
	char	width[10];
	char	*stemp;

	stemp = tab->temp;
	i = 0;
	stemp++;
	if (*stemp == '*')
		i = va_arg(tab->args, int);
	else
	{
		while (ft_isdigit(*stemp) || *stemp == '.' || *stemp == '-')
		{
			if (ft_isdigit(*stemp) || *stemp == '.' )
				width[i++] = *stemp;
			stemp++;
		}
		stemp = ft_strchr(width, '.');
		stemp++;
		i = ft_atoi(stemp);
	}
	return (i);
}
