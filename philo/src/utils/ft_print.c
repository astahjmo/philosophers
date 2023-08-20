#include "philo.h"

static size_t	ft_sstrlen(const char *src)
{
	size_t	count;

	count = 0;
	while (src[count])
		count++;
	return (count);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstt;
	size_t	srcc;

	dstt = 0;
	srcc = 0;
	while (dst[dstt] && dstt < size)
		dstt++;
	while (src[srcc] && (dstt + srcc + 1) < size)
	{
		dst[dstt + srcc] = src[srcc];
		srcc++;
	}
	if (dstt != size)
		dst[dstt + srcc] = 0;
	return (dstt + ft_sstrlen(src));
}

void	print_data(t_philo philo)
{
	char	*message;


}
