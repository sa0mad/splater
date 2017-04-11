#ifndef __SPLAT_DEM_H
#define __SPLAT_DEM_H

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
extern	int	dem_get_max_el(int index);
extern	void	dem_set_min_el(int indx, int min_el);
extern	int	dem_get_min_el(int index);
extern	void	dem_set_data(int indx, int x, int y, short data);
extern	void	dem_inc_data(int indx, int x, int y, short data);
extern	short	dem_get_data(int indx, int x, int y);
extern	void	dem_set_signal(int indx, int x, int y, unsigned char signal);
extern	unsigned char	dem_get_signal(int indx, int x, int y);
extern	void	dem_set_mask(int indx, int x, int y, unsigned char mask);
extern	unsigned char	dem_get_mask(int indx, int x, int y);

#endif // __SPLAT_DEM_H
