all: splat splat-hd

CPU=x86_64
MODEL=-mcmodel=medium

SPLATFILES=itwom3.0.cpp splat.cpp mathextra.c site.c

std-parms.h:
	echo "/* Parameters for 3 arc-second standard resolution mode of operation */" > std-parms.h

	echo "#define MAXPAGES 9" >> std-parms.h
	echo "#define HD_MODE 0" >> std-parms.h

hd-parms.h:
	echo "/* Parameters for 3 arc-second standard resolution mode of operation */" > hd-parms.h

	echo "#define MAXPAGES 9" >> hd-parms.h
	echo "#define HD_MODE 1" >> hd-parms.h

splat: std-parms.h $(SPLATFILES)
	cp std-parms.h splat.h
	g++ -O2 -s -fomit-frame-pointer -ffast-math -pipe $(MODEL) $(SPLATFILES) -lm -lbz2 -o splat

splat-hd: hd-parms.h $(SPLATFILES)
	cp hd-parms.h splat.h
	g++ -O2 -s -fomit-frame-pointer -ffast-math -pipe $(MODEL) $(SPLATFILES) -lm -lbz2 -o splat-hd

dist-clean:
	rm -f *~ splat splat-hd splat.h std-parms.h hd-parms.h utils/fontdata \
		utils/citydecoder utils/usgs2sdf \
		utils/srtm2sdf utils/srtm2sdf-hd utils/bearing

