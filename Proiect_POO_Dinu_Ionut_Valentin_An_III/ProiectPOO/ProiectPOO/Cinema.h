#include <iostream>
#include <string>
//#include "Cinema.h"
using namespace std;

class Cinema {
	Film film;
public:
	Cinema();
	Cinema(Film film);

	Film getFilm();
	void setFilm(Film filmNou);

	friend ostream& operator<<(ostream& out, const Cinema& cinema);
	friend istream& operator>>(istream& in, Cinema& cinema);

	bool operator!=(const Cinema c);
	bool operator==(Cinema c);
};