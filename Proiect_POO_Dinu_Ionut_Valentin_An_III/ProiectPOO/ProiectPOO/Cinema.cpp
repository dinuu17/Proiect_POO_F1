#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Cinema.h"
using namespace std;

Cinema::Cinema()
{
	film = Film::Film();
}
Cinema::Cinema(Film film)
{
	this->film = film;
}
Film Cinema::getFilm()
{
	return film;
}
void Cinema::setFilm(Film filmNou)
{
	film = filmNou;
}
ostream& operator<<(ostream& out, const Cinema& cinema)
{
	out << cinema.film;
	return out;
}
istream& operator>>(istream& in, Cinema& cinema)
{
	in >> cinema.film;
	return in;
}

bool Cinema::operator!=(Cinema c)
{
	if (strcmp(film.getBilet().getBilet(), c.film.getBilet().getBilet()) == 0)
		return false;
	return true;
}

bool Cinema::operator ==(Cinema c) {
	return this->film == c.film;
}

//INCA UN OPERATOR