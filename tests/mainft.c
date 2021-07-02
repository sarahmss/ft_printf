/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:27:32 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/02 10:01:00 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{

/**/
	//s
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("---------------------------------String----------------------------------------------");
	ft_printf("\n");
	ft_printf("%-60s: |%s|", "format identifier", "Quarante-deux");
	ft_printf("\n");
	ft_printf("%-60s: |%20s|", "with minimum field (20) width", "Quarante-deux");
	ft_printf("\n");
	ft_printf("%-60s: |%-20s|", "minimum field (20) left-align", "Quarante-deux");
	ft_printf("\n");
	ft_printf("%-60s: |%-*s|", "minimum field (*20) left-align", 20, "Quarante-deux");
	ft_printf("\n");
	ft_printf("%-60s: |%.8s|", "precision (8) field", "Quarante-deux");
	ft_printf("\n");
	ft_printf("%-60s: |%-.8s|", "precision(8) field left-align", "Quarante-deux");
	ft_printf("\n");
	ft_printf("%-60s: |%20.8s|", "minimum (20) and precision (8) field", "Quarante-deux");
	ft_printf("\n");
	ft_printf("%-60s: |%-20.8s|", "minimum (20) and precision (8) field left align", "Quarante-deux");
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*s|", "minimum (20) and precision (8) field left align",20, 8, "Quarante-deux");
	ft_printf("\n");
	ft_printf("\n");
	//c
	ft_printf("---------------------------------Character----------------------------------------------");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("%-60s: |%c|", "format identifier", 'x');
	ft_printf("\n");
	ft_printf("%-60s: |%-20c|", "minimum field (20) left align", 'x');
	ft_printf("\n");
	ft_printf("%-60s: |%-*c|", "minimum (8) field(*) left align", 8,'x');
	ft_printf("\n");
	ft_printf("\n");

	ft_printf("---------------------------------Pointer----------------------------------------------");
	int *pointer;
	int num;

	num = 42;
	pointer = &num;
	ft_printf("\n");
	ft_printf("%-60s: |%p|","format identifier", pointer);
	ft_printf("\n");
	ft_printf("%-60s: |%20p|", "with minimum field (20) width", pointer);
	ft_printf("\n");
	ft_printf("%-60s: |%-20p|\n", "minimum field (20) left align", pointer);
	ft_printf("\n");
	ft_printf("\n");

	ft_printf("---------------------------------decimal_signed_int----------------------------------------------");
	ft_printf("\n");
	ft_printf("\n");
	int hex_neg = -0x2a;

	ft_printf("%-60s: |%d|","format identifier", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%d|","(hex) format identifier", hex_neg);
	ft_printf("\n");
	ft_printf("%-60s: |%-3d|", "with minimum field (3) width", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%5d|", "with minimum field (5) width", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%05d|", "with minimum field (5) width and 0 padding", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%5.3d|", "minimum field (5) width with 0's", -42); // | -042|
	ft_printf("\n");
	ft_printf("%-60s: |%-5d|", "minimum field (5) left align", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%5.1d|", "precision (1) and minimum (5) field", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%.3d|", "precision (3) field", hex_neg);
	ft_printf("\n");
	ft_printf("%-60s: |%-.5d|", "precision (5) field left align", hex_neg);
	ft_printf("\n");
	ft_printf("%-60s: |%10.5d|", "minimum (10) and precision (5) field", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%-10.5d|", "minimum (10) and precision (5) field left align", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*d|", "minimum (20) and precision (1) field left align", 20, 1, hex_neg);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
/**/	// i
	ft_printf("-----------------------------------------------integer--------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("%-60s: |%i|","format identifier", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%20i|", "with minimum field (20) width", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%020i|", "minimum field (20) width with 0's", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%-20i|", "minimum field (20) left align", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%20.1i|", "precision (1) and minimum (20) field", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%.1i|", "precision (1) field", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%-.1i|", "(hex_neg) precision (1) field left align", hex_neg);
	ft_printf("\n");
	ft_printf("%-60s: |%020.10i|", "minimum (20) and precision (10) field", -12345678);
	ft_printf("\n");
	ft_printf("%-60s: |%-20.10i|", "minimum (20) and precision (10) field left align", -12345678);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*i|", "(hex_neg) minimum (20) and precision (1) field left align", 20, 1, hex_neg);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	//u
	ft_printf("-------------------------------------------unsigned_integer------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("%-60s: |%u|","negative input", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%u|","format identifier", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%20u|", "with minimum field (20) width", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%020u|", "minimum field (20) width with 0's", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%-20u|", "minimum field (20) left align", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%20.1u|", "precision (1) and minimum (20) field", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%.1u|", "precision (1) field", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%-.1u|", "(hex_neg) precision (1) field left align", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%-20.1u|", "minimum (20) and precision (1) field left align", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*u|", "(hex_neg) minimum (20) and precision (1) field left align", 20, 1, 42);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");

	// x
	ft_printf("---------------------------------------------hex_integer_lowercase----------------------------------------------------\n");

	int hex = 0x9f4;
	int integer = 42;

	ft_printf("\n");
	ft_printf("%-60s: |%x|","(int) format identifier", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%x|","(hex) format identifier", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%20x|", "(int) with minimum field (20) width", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%20x|", "(hex) with minimum field (20) width", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%020x|", "(int) minimum field (20) width with 0's", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%020x|", "(hex) minimum field (20) width with 0's", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%-20x|", "(int) minimum field (20) left align", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%-20x|", "(hex) minimum field (20) left align", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%20.6x|", "precision (6) and minimum (20) field", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%.6x|", "precision (6) field", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%-.6x|", "(hex_neg) precision (6) field left align", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%-20.6x|", "minimum (20) and precision (6) field left align", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*x|", "(hex_neg) minimum (20) and precision (6) field left align", 20, 6, hex);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	//X
	ft_printf("---------------------------------------------hex_integer_uppercase----------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("%-60s: |%X|","(int) format identifier", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%X|","(hex) format identifier", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%20X|", "(int) with minimum field (20) width", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%20X|", "(hex) with minimum field (20) width", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%020X|", "(int) minimum field (20) width with 0's", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%020X|", "(hex) minimum field (20) width with 0's", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%-20X|", "(int) minimum field (20) left align", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%-20X|", "(hex) minimum field (20) left align", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%20.6X|", "precision (6) and minimum (20) field", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%.6X|", "precision (6) field", integer);
	ft_printf("\n");
	ft_printf("%-60s: |%-.6X|", "(hex_neg) precision (6) field left align", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%-20.6X|", "minimum (20) and precision (6) field left align", hex);
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*X|", "(hex_neg) minimum (20) and precision (6) field left align", 20, 6, hex);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	// %
	ft_printf("--------------------------------------------------------%%---------------------------------------------------------------\n");
	ft_printf("|%0%|");
	ft_printf("\n");
	ft_printf("|%5%|");
	ft_printf("\n");
	ft_printf("|%0.5%|");
	ft_printf("\n");
	ft_printf("|%-10.4%|");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");

	return (0);
}
