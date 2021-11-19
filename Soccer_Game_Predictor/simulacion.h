#ifndef _SIM
#define _SIM

#include<vector>
#include<string>
#include"equipo.h"
#include"partido.h"

class simulacion {

public:
	int l;
	int e;
	int v;
	partido *p;
	std::vector<resultado> rr;
	
	
	simulacion(partido *, int);
	float p_local();
	float p_empate();
	float p_visita();
	float p_resultado(int, int);
	std::string reporte();
	
};


#endif
