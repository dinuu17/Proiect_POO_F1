#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Bilet.h"
using namespace std;

int Bilet::nrB = 1;

Bilet::Bilet()  : numarBilete(nrB++)
{
	denumire = nullptr;
	zona = nullptr;
	locuri = nullptr;
	data="";
	ora="";
	pretBilet = 0;
	nrLocuri = 0;
	nrRanduri = 0;
}

Bilet::Bilet(const char* denumire) : numarBilete(nrB++)
{
	if (denumire != nullptr)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else
	{
		this->denumire = nullptr;
	}
	zona = nullptr;
	locuri = nullptr;
	data = "";
	ora = "";
	pretBilet = 0;
	nrLocuri = 0;
	nrRanduri = 0;

}

Bilet::Bilet(const Bilet& b) : numarBilete(b.numarBilete)
{
	if (b.denumire != nullptr)
	{
		denumire = new char[strlen(b.denumire) + 1];
		strcpy_s(denumire, strlen(b.denumire) + 1, b.denumire);
	}
	else
	{
		denumire = nullptr;
	}
	if (b.zona != nullptr)
	{
		zona = new char[strlen(b.zona) + 1];
		strcpy_s(zona, strlen(b.zona) + 1, b.zona);
	}
	else
	{
		zona = nullptr;
	}
	if (b.locuri != nullptr && b.nrLocuri > 0)
	{
		numarLocuri = b.nrLocuri;
		locuri = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++)
			locuri[i] = b.locuri[i];
	}
	else
	{
		locuri = nullptr;
		nrLocuri= 0;
	}
	
}

Bilet::~Bilet()
{
	if (denumire != nullptr)
	{
		delete[] denumire;
		denumire = nullptr;
	}
	if (zona != nullptr)
	{
		delete[] zona;
		zona = nullptr;
	}
	if (locuri != nullptr)
	{
		delete[] locuri;
		locuri = nullptr;
	}
}

Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b)
	{
		if (locuri != nullptr)
		{
			delete[] locuri;
			locuri = nullptr;
		}
		if (denumire != nullptr)
		{
			delete[] denumire;
			denumire = nullptr;
		}
		if (zona != nullptr)
		{
			delete[] zona;
			zona = nullptr;
		}
		if (b.denumire != nullptr)
		{
			denumire = new char[strlen(b.denumire) + 1];
			strcpy_s(denumire, strlen(b.denumire) + 1, b.denumire);
		}
		else
			denumire= nullptr;
		if (b.zona != nullptr)
		{
			zona = new char[strlen(b.zona) + 1];
			strcpy_s(zona, strlen(b.zona) + 1, b.zona);
		}
		else
			zona = nullptr;


		if (b.locuri != nullptr && b.nrLocuri > 0)
		{
			nrLocuri= b.nrLocuri;
			locuri = new int[nrLocuri];
			for (int i = 0; i < nrLocuri; i++)
				locuri[i] = b.locuri[i];
		}
		else
		{
			locuri = nullptr;
			nrLocuri = 0;
		}

		this->data = b.data;
		this->ora = b.ora;
		this->pretBilet = b.pretBilet;
		this->nrRanduri = b.nrRanduri;
	}
	return *this;
}

int& Bilet::operator[](int index)
{
	if (index >= 0 && index < nrLocuri)
	{
		return locuri[index];
	}
	else
		throw exception("Index incorect");
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Data: ";
	in >> ws;
	getline(in, b.data);

	cout << "Ora: ";
	in >> ws;
	getline(in, b.ora);

	if (b.denumire != nullptr)
	{
		delete[]b.denumire;
	}
	cout << "Denumire film : ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	b.denumire = new char[strlen(buffer) + 1];
	strcpy_s(b.denumire, strlen(buffer) + 1, buffer);

	if (b.zona != nullptr)
	{
		delete[]b.zona;
	}
	cout << "Zona : ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	b.zona = new char[strlen(buffer) + 1];
	strcpy_s(b.zona, strlen(buffer) + 1, buffer);

	cout << "Numar locuri: ";
	in >> b.nrLocuri;

	cout << "Pret bilet: ";
	in >> b.pretBilet;

	if (b.locuri != nullptr)
	{
		delete[] b.locuri;
		b.locuri = nullptr;
	}

	b.locuri = new int[b.nrLocuri];
	cout << "Locuri : ";
	for (int i = 0; i < b.nrLocuri; i++)
	{
		in >> b.locuri[i];
	}

	return in;
}

ostream& operator<<(ostream& out, const Bilet& b)
{

	out << "Ora: " << b.ora << endl;
	out << "Data: " << b.data << endl;
	if (b.denumire != nullptr)
	{
		out << "Denumire film : " << b.denumire << endl;
	}
	if (b.zona != nullptr)
	{
		out << "Zona : " << b.zona << endl;
	}
	out << "Numar locuri: " << b.nrLocuri << endl;

	out << "Pret bilet: " << b.pretBilet << endl;

	out << "Locuri : ";
	for (int i = 0; i < b.nrLocuri; i++)
	{
		out << b.locuri[i] << " ";
	}
	out << endl;

	return out;

}

string Bilet::getOra()
{
	return this->Ora;
}

string Bilet::getData()
{
	return this->Data;
}

char* Bilet::getDenumire()
{
	if (denumire != nullptr)
	{
		char* copy = new char[strlen(denumire) + 1];
		strcpy_s(copy, strlen(denumire) + 1, denumire);
		return copy;
	}
	else
		return nullptr;
}

char* Bilet::getZona()
{
	if (zona != nullptr)
	{
		char* copy = new char[strlen(zona) + 1];
		strcpy_s(copy, strlen(zona) + 1, zona);
		return copy;
	}
	else
		return nullptr;
}

int* Bilet::getLocuri()
{
	if (locuri != nullptr && nrLocuri > 0)
	{
		int* copy = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++)
			copy[i] = locuri[i];
		return copy;
	}
	else
		return nullptr;
}

int Bilet::getNrLocuri()
{
	return nrLocuri;
}

int Bilet::getPretBilet()
{
	return pretBilet;
}

int Bilet::getnumarBilete()
{
	return numarBilete;
}

void Bilet::setOra(string oraNoua)
{
	ora = oraNoua;
}

void Bilet::setData(string dataNoua)
{
	data = dataNoua;
}

void Bilet::setDenumire(const char* denumireNoua)
{
	if (denumireNoua != nullptr)
	{
		if (denumire != nullptr)
			delete[] denumire;
		denumire = new char[strlen(denumireNoua) + 1];
		strcpy_s(denumire, strlen(denumireNoua) + 1, denumireNoua);
	}
}

void Bilet::setZona(const char* zonaNoua)
{
	if (zonaNoua != nullptr)
	{
		if (zona != nullptr)
			delete[] zona;
		zona = new char[strlen(zonaNoua) + 1];
		strcpy_s(zona, strlen(zonaNoua) + 1, zonaNoua);
	}
}

void Bilet::setLocuri(int* locuriNoua, int nrLocuriNoua)
{
	if (locuriNoua != nullptr && nrLocuriNoua > 0)
	{
		nrLocuri = nrLocuriNoua;
		if (locuri != nullptr)
			delete[] locuri;
		locuri = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++)
			locuri[i] = locuriNoua[i];
	}
}

void Bilet::setNrLocuri(int nrLocuriNoua)
{
	nrLocuri = nrLocuriNoua;
}

void Bilet::setPretBilet(int pretBiletNoua)
{
	pretBilet = pretBiletNoua;
}


void Bilet::zonaLoc(Bilet b)
{
	cout << "Biletul se afla in zona: " << b.zona;
}

void Bilet::biletVIP(Bilet b)
{
	if (b.pretBilet > 100)
	{
		cout << "Biletul este unul tip VIP";
	}
	else
	{
		cout << "Biletul nu este unul de tip VIP";
	}
}

void Bilet::homeAlone(Bilet b)
{
	if (strcmp(b.denumire, "HomeAlone") == 0)
		cout << "Biletul achizitionat este la filmul HomeAlone" << endl;
	else cout << "Biletul achizitionat NU este la filmul HomeAlone" << endl;
}

