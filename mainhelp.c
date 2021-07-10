#include "includes/ft_printf.h"

int	main(void)
{
	ft_printf(" p6: | %10p %10p |", 1, -1);
	ft_printf("\n");
	ft_printf(" p7: | %-10p %10p |", 1, -1);
	return (0);
}
