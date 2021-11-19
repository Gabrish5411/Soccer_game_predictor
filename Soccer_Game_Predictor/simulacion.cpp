#include"simulacion.h"


#include<sstream>

using namespace std;

simulacion::simulacion(partido *a, int n) {
	p=a;
	resultado r(0,0);
	for(int i=0;i<n;i++) {
		r=p->simular();
		if(r.goles[0]>r.goles[1])
			l++;
		else if(r.goles[0]==r.goles[1])
			e++;
		else v++;
		rr.push_back(r);
	}	
}
float simulacion::p_local() {
	return (float(l))/(float(rr.size()));
}
float simulacion::p_empate() {
	return (float(e))/(float(rr.size()));
}
float simulacion::p_visita() {
	return (float(v))/(float(rr.size()));
}
float simulacion::p_resultado(int l, int v) {
	int k=0;
	for(size_t i=0;i<rr.size();i++)
		if(l==rr[i].goles[0] && v==rr[i].goles[1])
			k++;
	return (float(k))/(float(rr.size()));
}

string simulacion::reporte() {
	stringstream ss("");
	ss<<p->get_nombre()<<endl;
	ss<<endl;
	ss<<"Probabilidades:"<<endl;
	ss<<"Local: "<<100*p_local()<<"%"<<endl;
	ss<<"Empate: "<<100*p_empate()<<"%"<<endl;
	ss<<"Visita: "<<100*p_visita()<<"%"<<endl;
	ss<<endl;
	ss<<"1-0: "<<100*p_resultado(1,0)<<"%"<<endl;
	ss<<"0-0: "<<100*p_resultado(0,0)<<"%"<<endl;
	ss<<"0-1: "<<100*p_resultado(0,1)<<"%"<<endl;
	return ss.str();
}

