#include <iostream>
#include <string>
//#include "Film.h";
using namespace std;

enum class Gen
{
	2D,
	3D,
	7D
};

class Film 
{
	static Gen gen;
	Bilet bilet;

public:
	Film();
	Film(Bilet bilet);

	Gen getGen();
	void setGen(Gen genNou);

	Bilet getBilet();
	void setBilet(Bilet biletNou);

	friend ostream& operator<<(ostream& out, const Film& f);
	friend istream& operator>>(istream& in, Film& f);

	bool operator!();
};