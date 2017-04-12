// Standard C includes
#include <math.h>

// Projects includes
#include "constants.h"
#include "global.h"

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

void	dem_set_elevation(int indx, int x, int y, int elevation)
{
	dem_set_data(indx, x, y, elevation);
	dem_set_signal(indx, x, y, 0);
	dem_set_mask(indx, x, y, 0);
	dem_setmax_el(indx, elevation);
	dem_setmin_el(indx, elevation);
}

void	dem_set_zero(int indx)
{
	int ippd, x, y;
	ippd = dem_get_ippd(indx);
	for (x=0; x<ippd; x++)
		for (y=0; y<ippd; y++)
		{
			dem_set_data(indx, x, y, 0);
			dem_set_signal(indx, x, y, 0);
			dem_set_mask(indx, x, y, 0);
			dem_set_max_el(indx, 0);
			dem_set_min_el(indx, 0);
		}
}

int	dem_diff_lat(int indx, double lat)
{
	int ippd = dem_get_ippd(indx);
	double ppd=(double)ippd;
	return (int)rint(ppd*(lat-dem_get_min_north(indx)));
}

int	dem_diff_lon(int indx, double lon)
{
	int ippd = dem_get_ippd(indx);
	double ppd=(double)ippd;
	int mpi = ippd - 1;
	return mpi-(int)rint(ppd*(LonDiff(dem_get_max_west(indx),lon)));
}

int	dem_find_indx(double lat, double lon, int * index, int *xp, int *yp)
{
	int	found;
	int	indx, x, y;
	for (indx=0, found=0; indx<MAXPAGES && found==0;)
	{
		int ippd = dem_get_ippd(indx);
		int mpi = ippd - 1;
		x = dem_diff_lat(indx, lat);
		y = dem_diff_lon(indx, lon);

		if (x>=0 && x<=mpi && y>=0 && y<=mpi)
			found=1;
		else
			indx++;
	}
	*index = indx;
	*xp = x;
	*yp = y;
	return found;
}
