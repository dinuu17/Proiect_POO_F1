#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Film.h"

using namespace std;

Gen Film::gen = Gen::2D;

Film::Film()
{
	bilet = Bilet::Bilet();
}
Film::Film(Bilet bilet) : FIlm()
{
	this->bilet = bilet;
}
Gen Film::getGen()
{
	return gen;
}
void Film::setGen(Gen genNou)
{
	gen = genNou;
}
Bilet Film::getBilet()
{
	return bilet;
}

void Film::setBilet(Bilet biletNou)
{
	bilet = biletNou;
}

ostream& operator<<(ostream& out, const Film& f)
{
	out << f.bilet;
	return out;
}
istream& operator>>(istream& in, Film& f)
{
	in >> f.bilet;
	return in;
}

bool Film::operator!()
{
	if (strlen(bilet.getBilet()) >= 3)
		return false;
	return true;
}

//INCA UN OPERATOR