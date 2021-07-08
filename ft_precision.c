/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:24:29 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/08 11:38:15 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_sup(char *stemp)
{
	char	width[10];
	int		i;

	i = 0;
	while (ft_isdigit(*stemp) || *stemp == '.' || *stemp == '-')
	{
		if (ft_isdigit(*stemp))
			width[i++] = *stemp;
		stemp++;
	}
	stemp = width;
	i = ft_atoi(stemp);
	if (i == 0)
		i = -1;
	return (i);
}

int	ft_precision(t_format *tab)
{
	int		i;
	char	*stemp;

	stemp = tab->temp;
	i = -1;
	while (*stemp != '.' )
		stemp++;
	stemp++;
	if (*stemp == '*')
	{
		i = va_arg(tab->args, int);
		if (i == 0)
			i = -1;
	}
	else if (!ft_isdigit(*stemp))
		return (i);
	else
		i = ft_sup(stemp);
	return (i);
}
