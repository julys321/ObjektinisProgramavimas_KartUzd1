#pragma once
#include <string>
#include "Bulves.h"
using namespace std;
class Ukininkas
{
public:
	string registracijosNumeris;
	Bulves parduotosBulves;
	Ukininkas *sekantisUkininkas = NULL;

	Ukininkas();
	Ukininkas(string registracijosNumeris, Bulves parduotosBulvesKilogramais) {
		this->registracijosNumeris = registracijosNumeris;
		this->parduotosBulves = parduotosBulvesKilogramais;
	}
	virtual ~Ukininkas();
};



Ukininkas::Ukininkas()
{
}


Ukininkas::~Ukininkas()
{
}
