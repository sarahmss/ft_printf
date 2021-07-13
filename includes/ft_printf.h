/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:03:47 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/13 10:01:52 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libraries/libft/libft.h"

typedef struct s_format
{
	va_list	args;
	char		*temp;
	int			width;
	int			precision;
	int			l_just;
	int			pad_zero;
	int			width_prm[2];
	int			printed;
	int			str;
	int			ch;
	int			in;
	int			hex;
	long int	num;
}			t_format;

int			ft_printf(const char *format, ...);

t_format	*ft_initialise_tab(t_format *tab);

char		*ft_eval_format(char *temp, t_format *tab);

int			ft_format(char *temp, t_format *tab);

void		ft_printstr(t_format *tab);

void		ft_printchar(t_format *tab);

int			ft_printint(char *temp, t_format *tab);

void		ft_printhex(char *temp, t_format *tab);

void		ft_flags(t_format *tab);

void		ft_width(t_format *tab);

int			ft_widthparam(t_format *tab, char *stemp);

void		ft_padzero(t_format *tab);

int			ft_precision(t_format *tab);

int			ft_intprecision(t_format *tab, int neg);

int			ft_findsize(t_format *tab, char *stemp, int i);

int			ft_findsize1(t_format *tab, int i);

#endif
