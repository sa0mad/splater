#ifndef __SPLAT_SITE_H
#define __SPLAT_SITE_H

typedef struct site site_t;

extern site_t site;

extern	site_t *	site_alloc();
extern	void	site_free(site_t * site);
extern	void	site_set_name(site_t * site1, char * name);
extern	char *	site_get_name(site_t * site1);
extern	void	site_set_lat(site_t * site, double lat);
extern	double	site_get_lat(site_t * site);
extern	void	site_set_lon(site_t * site, double lon);
extern	double	site_get_lon(site_t * site);
extern	void	site_set_alt(site_t * site, double alt);
extern	double	site_get_alt(site_t * site);
extern	void	site_set_filename(site_t * site, char * filename);
extern	char *	site_get_filename(site_t * site1);
extern	void	site_get_filename_cpy(site_t * site, char * filename);

extern site_t * LoadQTH(char *filename);
extern double GetElevation(site_t * location);
extern int AddElevation(double lat, double lon, double height);
extern double Distance(site_t * site1, site_t * site2);
extern double Azimuth(site_t * source, site_t * destination);
extern double ElevationAngle(site_t * source, site_t * destination);
extern void ReadPath(site_t * source, site_t * destination);
extern double ElevationAngle2(site_t * source, site_t * destination, double er);
extern double AverageTerrain(site_t * source, double azimuthx, double start_distance, double end_distance);
extern double haat(site_t * antenna);
extern void PlaceMarker(site_t * location);

#endif // __SPLAT_SITE_H
