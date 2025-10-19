#include <unistd.h>
#define N 4

void	write_int(int val)
{
	char	buf[16];
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (val == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (val < 0)
	{
		neg = 1;
		val = -val;
	}
	while (val > 0)
	{
		buf[i++] = '0' + (val % 10);
		val /= 10;
	}
	if (neg)
		buf[i++] = '-';
	while (i-- > 0)
		write(1, &buf[i], 1);
}

