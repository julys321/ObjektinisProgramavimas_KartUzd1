#pragma once
#include <string>
#include <fstream>
#include "Ukininkas.h"
#include "UkininkuVienkryptisSarasas.h"
class DuomenuPildytojas
{
public:
	DuomenuPildytojas();
	virtual ~DuomenuPildytojas();

	void pildykUkininkuVienkryptiSarasa(UkininkuVienkryptisSarasas &ukininkai) {
		ifstream ukininkuDuomenysStream("ObjektinisProgramavimas_KartUzd1_Duom.txt");
		int ukininkuKiekis;
		ukininkuDuomenysStream >> ukininkuKiekis;
		Ukininkas ukininkas;
		for (int i = 0; i < ukininkuKiekis; i++) {
			ukininkuDuomenysStream >> ukininkas.registracijosNumeris >> ukininkas.parduotosBulves.kiekis;
			//ukininkas.registracijosNumeris = string(temp);
			ukininkai.add(ukininkas);
		}
		ukininkuDuomenysStream.close();
	}
};



DuomenuPildytojas::DuomenuPildytojas()
{
}


DuomenuPildytojas::~DuomenuPildytojas()
{
}
