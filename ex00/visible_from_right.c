#include <unistd.h>
#define N 4

int	visible_from_right(int *row)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = N - 1;
	while (i >= 0)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i--;
	}
	return (count);
}

