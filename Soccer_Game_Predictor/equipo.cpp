#include"equipo.h"

equipo::equipo(std::string n, float r) {
	nombre=n;
	rating=r;
}

float equipo::get_rating() {
	return rating;
}

std::string equipo::get_nombre() {
	return nombre;
}
