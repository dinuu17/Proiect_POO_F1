#include <iostream>
#include <string>
using namespace std;

class Bilet {
	int* locuri;
	int nrLocuri;
	int nrRanduri; // STERGE !!!
	char* zona;  // char simplu
	string data;
	string ora;
	char* denumire;
	const int numarBilete;
	static int nrB;
	static string mesajFinalizare;
public:
	Bilet();
	Bilet(const char* denumire);
	Bilet(const Bilet& b);
	~Bilet();

	Bilet& operator=(const Bilet& b);

	string Bilet::getOra();
	void Bilet::setOra(string oraNoua);

	string Bilet::getData();
	void Bilet::setData(string dataNoua);

	char* Bilet::getDenumire();
	void Bilet::setDenumire(const char* denumireNoua);

	char* Bilet::getZona();
	void Bilet::setZona(const char* zonaNoua);

	int* Bilet::getLocuri();
	void setLocuri(int* locuriNoua, int nrLocuriNoua);

	int Bilet::getNrLocuri();
	void Bilet::setNrLocuri(int nrLocuriNoua);

	int Bilet::getnumarBilete();



	friend istream& operator>>(istream& in, Bilet& b);

	friend ostream& operator<<(ostream& out, const Bilet& b);
	
	int& operator[](int index);

	void zonaLoc(Bilet b);
	void homeAlone(Bilet b);
	
};

string Bilet::mesajFinalizare = "Enjoy ! :)";
