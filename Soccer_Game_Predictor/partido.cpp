#include"partido.h"
#include<cstdlib>
#include<cmath>

resultado::resultado(int l, int v) {
	goles[0]=l;
	goles[1]=v;
}

int goles(float eg) {
	float u=((float)rand())/(float)RAND_MAX;
	int i=0;
	float l=eg;
	float p=exp(-l);
	while(u>p) {
		i++;
		u-=p;
		p*=(l/i);
	}
	return i;
}

partido::partido(equipo *e1, equipo *e2) {
	local=e1;
	visita=e2;
}

resultado partido::simular() {
	float edg=(local->get_rating()+100-visita->get_rating())/400;
	float egl=(edg+sqrt(edg*edg+4))/2;
	float egv=egl-edg;
	return resultado(goles(egl),goles(egv));
}

std::string partido::get_nombre() {
	return "" + local->get_nombre() + " v/s " + visita->get_nombre();
}
