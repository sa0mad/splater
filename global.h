#ifndef __SPLAT_GLOBAL_H
#define __SPLAT_GLOBAL_H

extern double earthradius;
extern double dpp;
extern double ppd;
extern double clutter;

extern int min_north;
extern int max_north;
extern int min_west;
extern int max_west;
extern int mpi;

typedef struct path path_t;

struct path {	double lat[ARRAYSIZE];
		double lon[ARRAYSIZE];
		double elevation[ARRAYSIZE];
		double distance[ARRAYSIZE];
		int length;
	    };

extern path_t	path;

extern int OrMask(double lat, double lon, int value);
extern int GetMask(double lat, double lon);
extern double LonDiff(double lon1, double lon2);
extern double ReadBearing(char *input);

#endif // __SPLAT_GLOBAL_H
