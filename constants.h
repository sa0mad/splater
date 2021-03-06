#ifndef __SPLAT_CONSTANTS_H
#define __SPLAT_CONSTANTS_H

#include "splat.h"

#define GAMMA 2.5
#define BZBUFFER 65536

#if HD_MODE==0
	#if MAXPAGES==4
	#define ARRAYSIZE 4950
	#endif

	#if MAXPAGES==9
	#define ARRAYSIZE 10870
	#endif

	#if MAXPAGES==16
	#define ARRAYSIZE 19240
	#endif

	#if MAXPAGES==25
	#define ARRAYSIZE 30025
	#endif

	#if MAXPAGES==36
	#define ARRAYSIZE 43217
	#endif

	#if MAXPAGES==49
	#define ARRAYSIZE 58813
	#endif

	#if MAXPAGES==64
	#define ARRAYSIZE 76810
	#endif

	#define IPPD 1200
#endif

#if HD_MODE==1
	#if MAXPAGES==1
	#define ARRAYSIZE 5092 
	#endif

	#if MAXPAGES==4
	#define ARRAYSIZE 14844 
	#endif

	#if MAXPAGES==9
	#define ARRAYSIZE 32600
	#endif

	#if MAXPAGES==16
	#define ARRAYSIZE 57713
	#endif

	#if MAXPAGES==25
	#define ARRAYSIZE 90072
	#endif

	#if MAXPAGES==36
	#define ARRAYSIZE 129650
	#endif

	#if MAXPAGES==49 
	#define ARRAYSIZE 176437
	#endif

	#if MAXPAGES==64
	#define ARRAYSIZE 230430
	#endif

	#define IPPD 3600
#endif

#endif // __SPLAT_CONSTANTS_H
