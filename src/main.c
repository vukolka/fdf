#include <Point.h>
#include "ft_printf.h"
#include "new.h"

int     main()
{
    string_init();
	point_init();
	void *s1 = new(string, "text");
	void *v1 = new(point, 2, 3, 5);
	void *v2 = clone(v1);
	ft_printf("%d", differ(v1, v2));
	return (0);
}