#include <iostream>
#include <string>
#include "UkininkuVienkryptisSarasas.h"
#include "DuomenuPildytojas.h"
#include "UkininkuSkaiciuotuvas.h"

using namespace std;

int main() {
	UkininkuVienkryptisSarasas ukininkai;
	DuomenuPildytojas duomenuPildytojas;
	duomenuPildytojas.pildykUkininkuVienkryptiSarasa(ukininkai);
	UkininkuDuomenuSkaiciuotuvas ukininkuDuomenuSkaiciuotuvas;

	cout << "Kiek kilogramų bulviu buvo parduota is viso? - " << ukininkuDuomenuSkaiciuotuvas.getBulviuSumaKilogramais(ukininkai) << endl;
	cout << "Kiek uzfiksuota irasu, kai buvo parduota daugiau kaip 50 kg bulviu? - " << ukininkuDuomenuSkaiciuotuvas.getUkininkaiPardaveBulviuDaugiau(ukininkai,50) << endl;
	cout << "Paskutinio ukinko parduotos bulves kg? - " << ukininkai.getPaskutinisUkininkas()->parduotosBulves.kiekis << " " << ukininkai.getPaskutinisUkininkas()->parduotosBulves.matavimoVienetas << endl;

	system("pause");
	return 0;
}
