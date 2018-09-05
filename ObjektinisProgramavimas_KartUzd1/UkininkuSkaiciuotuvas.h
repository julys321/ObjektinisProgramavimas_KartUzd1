#pragma once
#include "UkininkuVienkryptisSarasas.h"
class UkininkuDuomenuSkaiciuotuvas
{
public:
	UkininkuDuomenuSkaiciuotuvas();
	virtual ~UkininkuDuomenuSkaiciuotuvas();

	int getBulviuKilogramaisSuma(UkininkuVienkryptisSarasas ukininkuVienkryptisSarasas) {
		int bulviuKilogramaisSuma = 0;
		Ukininkas *ukininkas = ukininkuVienkryptisSarasas.pirmasukininkas;
		while (ukininkuVienkryptisSarasas.ukininkasNeraPaskutinis(ukininkas)) {
			if (ukininkuVienkryptisSarasas.ukininkoParduotosBulvesYraKilogramais(ukininkas))
				bulviuKilogramaisSuma += ukininkas->parduotosBulves.kiekis;
			ukininkas = ukininkas->sekantisUkininkas;
		}
		return bulviuKilogramaisSuma;
	}

	int getUkininkaiPardaveBulviuDaugiau(UkininkuVienkryptisSarasas ukininkuVienkryptisSarasas, int minimumas) {
		int ukininkaiPardaveBulviuDaugiau = 0;
		Ukininkas *ukininkas = ukininkuVienkryptisSarasas.pirmasukininkas;
		while (ukininkuVienkryptisSarasas.ukininkasNeraPaskutinis(ukininkas)) {
			if (ukininkas->parduotosBulves.kiekis > minimumas)
				ukininkaiPardaveBulviuDaugiau++;
			ukininkas = ukininkas->sekantisUkininkas;
		}
		return ukininkaiPardaveBulviuDaugiau;
	}
};



UkininkuDuomenuSkaiciuotuvas::UkininkuDuomenuSkaiciuotuvas()
{
}


UkininkuDuomenuSkaiciuotuvas::~UkininkuDuomenuSkaiciuotuvas()
{
}
