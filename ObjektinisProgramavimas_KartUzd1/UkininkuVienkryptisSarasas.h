#pragma once
#include <string>
#include "Bulves.h"
#include "Ukininkas.h"
using namespace std;
class UkininkuVienkryptisSarasas
{
public:
	Ukininkas * pirmasukininkas = NULL;
	int ukininkuSkaicius = 0;

	UkininkuVienkryptisSarasas();
	virtual ~UkininkuVienkryptisSarasas();

	void add(Ukininkas &ukininkas) {
		if (pirmasukininkas == NULL) {
			pirmasukininkas = new Ukininkas(ukininkas.registracijosNumeris, ukininkas.parduotosBulves);
		}
		else {
			Ukininkas *paskutinisUkininkas = getPaskutinisUkininkas();
			paskutinisUkininkas->sekantisUkininkas = new Ukininkas(ukininkas.registracijosNumeris, ukininkas.parduotosBulves);
		}
		ukininkuSkaicius++;
	}

	Ukininkas* getPaskutinisUkininkas() {
		Ukininkas *paskutinisUkininkas = pirmasukininkas;
		while (sekantisUkininkasNeraPaskutinis(paskutinisUkininkas)) {
			paskutinisUkininkas = paskutinisUkininkas->sekantisUkininkas;
		}
		return paskutinisUkininkas;
	}

	bool sekantisUkininkasNeraPaskutinis(Ukininkas *ukininkas) {
		if (ukininkas->sekantisUkininkas != NULL)
			return true;
		else
			return false;
	}

	bool ukininkasNeraPaskutinis(Ukininkas *ukininkas) {
		if (ukininkas != NULL)
			return true;
		else
			return false;
	}

	bool ukininkoParduotosBulvesYraKilogramais(Ukininkas *ukininkas) {
		if (ukininkas->parduotosBulves.matavimoVienetas == "kilogramai")
			return true;
		else
			return false;
	}

};



UkininkuVienkryptisSarasas::UkininkuVienkryptisSarasas()
{
}


UkininkuVienkryptisSarasas::~UkininkuVienkryptisSarasas()
{
}
