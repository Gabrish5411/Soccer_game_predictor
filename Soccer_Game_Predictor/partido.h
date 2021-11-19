#ifndef _PARTIDO
#define _PARTIDO

#include"equipo.h"

class resultado {
public:
	int goles[2];
	resultado(int,int);
};

class partido {
private:
	equipo *local;
	equipo *visita;
public:
	partido(equipo *, equipo *);
	resultado simular();
	std::string get_nombre();
};

#endif
