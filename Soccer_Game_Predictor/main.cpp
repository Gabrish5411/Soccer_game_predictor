#include<iostream>

#include"equipo.h"
#include"partido.h"
#include"simulacion.h"

using namespace std;

#include<cstdlib>
#include<ctime>

int main() {
	srand(time(NULL));
	equipo e("Brasil", 2154);
	equipo f("Argentina", 2023);
	partido p(&e, &f);
	simulacion s(&p, 10000);
	cout<<s.reporte();
	return 0;
}
