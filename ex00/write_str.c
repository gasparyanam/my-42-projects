#include <unistd.h>
#define N 4

void	write_str(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (len > 0)
		write(1, s, len);
}

