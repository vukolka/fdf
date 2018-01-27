#include <ft_printf.h>
#include "../fdf.h"

void	ft_print_error(int error)
{
	ft_printf("error: ");
	if (error == DIFF_LINES)
		ft_printf("file should be of rectangular shape");
	if (error == EMPTY_LINES)
		ft_printf("empty line in the end or the beginning of the file");
	if (error == NOT_A_NUMBER)
		ft_printf("lines should only contain decimal or hexadecimal numbers");
	ft_printf("\n");
	exit(1);
}