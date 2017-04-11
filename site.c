// Standard C includes
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Project includes
#include "fontdata.h"
#include "splat.h"
#include "constants.h"
#include "global.h"
#include "mathextra.h"

// Module include
#include "site.h"

struct site {
	double	lat;
	double	lon;
	double	alt;
	char *	name;
	char *	filename;
};

site_t *	site_alloc()
{
	return (site_t *)malloc(sizeof(site_t));
}

void	site_free(site_t * site)
{
	free(site);
}

void	site_set_name(site_t * site, char * name)
{
	strncpy(site->name,name,49);
}

char *	site_get_name(site_t * site)
{
	return site->name;
}

void	site_set_lat(site_t * site, double lat)
{
	site->lat = lat;
}

double	site_get_lat(site_t * site)
{
	return site->lat;
}

void	site_set_lon(site_t * site, double lon)
{
	site->lon = lon;
}

double	site_get_lon(site_t * site)
{
	return site->lon;
}

void	site_set_alt(site_t * site, double alt)
{
	site->alt = alt;
}

double	site_get_alt(site_t * site)
{
	return site->alt;
}

void	site_set_pos(site_t * site, double lat, double lon, double alt)
{
	site->lat = lat;
	site->lon = lon;
	site->alt = alt;
}

void	site_set_filename(site_t * site, char * filename)
{
	site->filename = filename;
}

char *	site_get_filename(site_t * site)
{
	return site->filename;
}

void	site_get_filename_cpy(site_t * site, char * filename)
{
	strcpy(filename, site->filename);
}
