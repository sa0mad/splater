#ifndef __SPLAT_MATHEXTRA_H
#define __SPLAT_MATHEXTRA_H

#ifndef PI
#define PI 3.141592653589793
#endif

#ifndef TWOPI
#define TWOPI 6.283185307179586
#endif

#ifndef HALFPI
#define HALFPI 1.570796326794896
#endif

#define DEG2RAD 1.74532925199e-02
// Mean radius as defined by IUGG https://en.wikipedia.org/wiki/Earth_radius
#define EARTHRADIUS_METER 6371008.8
#define	METERS_PER_MILE 1609.344
#define METERS_PER_FOOT 0.3048
#define	FOOT_PER_METERS	3.28084
#define	FOOT_PER_MILE 5280.0
#define	KM_PER_MILE 1.609344
#define MILE_PER_METER (1.0/METERS_PER_MILE)
#define FOUR_THIRDS 1.3333333333333

extern double arccos(double x, double y);

#endif // __SPLAT_MATHEXTRA_H
