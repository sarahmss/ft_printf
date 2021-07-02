/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:02:23 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/29 14:33:03 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_main_printf(char *str, t_format *tab)
{
	char		*temp;

	if (!(ft_strchr(str, '%')))
	{
		tab->printed += ft_putstr_fd(str, 1);
		return (tab->printed);
	}
	temp = ft_strcdup(str, '%');
	if (!temp)
		return (-1);
	tab->printed += ft_putstr_fd(temp, 1);
	free (temp);
	temp = ft_strchr(str, '%');
	temp = ft_eval_format(temp, tab);
	return (ft_main_printf(temp, tab));
}

int	ft_printf(const char *format, ...)
{
	t_format	*tab;

	tab = (t_format *)malloc(sizeof(t_format));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	tab->printed = ft_main_printf((char *)format, tab);
	return (tab->printed);
}
