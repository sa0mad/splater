#ifndef __SPLAT_DEM_H
#define __SPLAT_DEM_H

// Projects includes
#include "site.h"

typedef struct dem dem_t;

extern dem_t dem[MAXPAGES];

extern	void	dem_set_ippd(int indx, int ippd);
extern	int	dem_get_ippd(int indx);
extern	void	dem_set_min_north(int indx, int min_north);
extern	int	dem_get_min_north(int indx);
extern	void	dem_set_max_north(int indx, int max_north);
extern	int	dem_get_max_north(int indx);
extern	void	dem_set_min_west(int indx, int min_west);
extern	int	dem_get_min_west(int indx);
extern	void	dem_set_max_west(int indx, int max_west);
extern	int	dem_get_max_west(int indx);
extern	void	dem_set_max_el(int indx, int max_el);
extern	void	dem_setmax_el(int indx, int el);
extern	int	dem_get_max_el(int index);
extern	void	dem_set_min_el(int indx, int min_el);
extern	void	dem_setmin_el(int indx, int el);
extern	int	dem_get_min_el(int index);
extern	void	dem_set_data(int indx, int x, int y, short data);
extern	void	dem_inc_data(int indx, int x, int y, short data);
extern	short	dem_get_data(int indx, int x, int y);
extern	void	dem_set_signal(int indx, int x, int y, unsigned char signal);
extern	unsigned char	dem_get_signal(int indx, int x, int y);
extern	void	dem_set_mask(int indx, int x, int y, unsigned char mask);
extern	void	dem_or_mask(int indx, int x, int y, unsigned char mask);
extern	unsigned char	dem_get_mask(int indx, int x, int y);
extern	void	dem_set_elevation(int indx, int x, int y, int elevation);
extern	void	dem_set_zero(int indx);
extern	int	dem_diff_lat(int indx, double lat);
extern	int	dem_diff_lon(int indx, double lon);
extern	int	dem_find_indx(double lat, double lon, int * index, int *xp, int *yp);
extern	int	dem_set_mask_pos(double lat, double lon, int value);
extern	int	dem_or_mask_pos(double lat, double lon, int value);
extern	int	dem_get_mask_pos(double lat, double lon);
extern	int	dem_set_signal_pos(double lat, double lon, unsigned char signal);
extern	unsigned char dem_get_signal_pos(double lat, double lon);
extern	double dem_get_elevation_loc(site_t * location);
extern	int dem_add_elevation_pos(double lat, double lon, double height);
extern	int	dem_exists(int minlat, int maxlat, int minlon, int maxlon);
extern	int	dem_freespace(int * indxp);

#endif // __SPLAT_DEM_H
