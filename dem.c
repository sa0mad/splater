// Standard C includes

// Projects includes
#include "constants.h"

// Module include
#include "dem.h"

struct dem {
	int ippd;
	int min_north;
	int max_north;
	int min_west;
	int max_west;
	int max_el;
	int min_el;
	short data[IPPD][IPPD];
	unsigned char mask[IPPD][IPPD];
	unsigned char signal[IPPD][IPPD];
};

dem_t	dem[MAXPAGES];

void	dem_set_ippd(int indx, int ippd)
{
	dem[indx].ippd = ippd;
}

int	dem_get_ippd(int indx)
{
	return dem[indx].ippd;
}

void	dem_set_min_north(int indx, int min_north)
{
	dem[indx].min_north = min_north;
}

int	dem_get_min_north(int indx)
{
	return dem[indx].min_north;
}

void	dem_set_max_north(int indx, int max_north)
{
	dem[indx].max_north = max_north;
}

int	dem_get_max_north(int indx)
{
	return dem[indx].max_north;
}

void	dem_set_min_west(int indx, int min_west)
{
	dem[indx].min_west = min_west;
}

int	dem_get_min_west(int indx)
{
	return dem[indx].min_west;
}

void	dem_set_max_west(int indx, int max_west)
{
	dem[indx].max_west = max_west;
}

int	dem_get_max_west(int indx)
{
	return dem[indx].max_west;
}

void	dem_set_max_el(int indx, int max_el)
{
	dem[indx].max_el = max_el;
}

void	dem_setmax_el(int indx, int el)
{
	if (el > dem[indx].max_el)
		dem[indx].max_el = el;
}

int	dem_get_max_el(int indx)
{
	return dem[indx].max_el;
}

void	dem_set_min_el(int indx, int min_el)
{
	dem[indx].min_el = min_el;
}

void	dem_setmin_el(int indx, int el)
{
	if (el < dem[indx].max_el)
		dem[indx].max_el = el;
}

int	dem_get_min_el(int indx)
{
	return dem[indx].min_el;
}

void	dem_set_data(int indx, int x, int y, short data)
{
	dem[indx].data[x][y] = data;
}

void	dem_inc_data(int indx, int x, int y, short data)
{
	dem[indx].data[x][y] += data;
}

short	dem_get_data(int indx, int x, int y)
{
	return dem[indx].data[x][y];
}

void	dem_set_signal(int indx, int x, int y, unsigned char signal)
{
	dem[indx].signal[x][y] = signal;
}

unsigned char	dem_get_signal(int indx, int x, int y)
{
	return dem[indx].signal[x][y];
}

void	dem_set_mask(int indx, int x, int y, unsigned char mask)
{
	dem[indx].mask[x][y] = mask;
}

unsigned char	dem_get_mask(int indx, int x, int y)
{
	return dem[indx].mask[x][y];
}
