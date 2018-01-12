#include <libft.h>

void	for_each_lst(t_list *lst, void (*f)(void *, int , int , int), ...)
{
	va_list ap;
	int x;
	int y;
	int z;

	va_start(ap, f);
	x = va_arg(ap, int);
	y = va_arg(ap, int);
	z = va_arg(ap, int);
	if (!lst)
		return ;
	while (lst)
	{
		f(lst, x, y, z);
		lst = lst->next;
	}
	va_end(ap);
}