#ifndef _EQUIPO
#define _EQUIPO

#include<string>

class equipo {
private:
	std::string nombre;
	float rating;
public:
	equipo(std::string, float);
	float get_rating();
	std::string get_nombre();
};

#endif
