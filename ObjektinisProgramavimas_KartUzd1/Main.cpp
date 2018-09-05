#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Ukininkas {
	char registracijosNumeris[3];
	long int parduotosBulvesKilogramais;
	Ukininkas *sekantisUkininkas;
};
struct UkininkuVienkryptisSarasas {
	Ukininkas *pirmasukininkas;
	int ukininkuSkaicius = 0;
public:
	void add(Ukininkas &ukininkas) {
		if (ukininkuSkaicius == 0) {
			ukininkas.sekantisUkininkas = NULL;
			pirmasukininkas = &ukininkas;
		}
		else {
			Ukininkas *paskutinisUkininkas = getPaskutinisUkininkas();
			paskutinisUkininkas->sekantisUkininkas = new Ukininkas;
			paskutinisUkininkas->sekantisUkininkas->sekantisUkininkas = NULL;
		}
		ukininkuSkaicius++;
	}
	Ukininkas* getPaskutinisUkininkas() {
		Ukininkas *paskutinisUkininkas = pirmasukininkas;
		while (paskutinisUkininkas->sekantisUkininkas != NULL) {
			paskutinisUkininkas = paskutinisUkininkas->sekantisUkininkas;
		}
		return paskutinisUkininkas;
	}





	vector<Ukininkas> ukininkai;
public:
	void addUkininkas(Ukininkas ukininkas) {
		ukininkai.push_back(ukininkas);
	}
	int getParduotuBulviuKilogramaisSkaicius() {
		int parduotuBulviuKilogramaisSkaicius = 0;
		for (Ukininkas ukininkas : ukininkai) {
			parduotuBulviuKilogramaisSkaicius += ukininkas.parduotosBulvesKilogramais;
		}
		return parduotuBulviuKilogramaisSkaicius;
	}
	int getUkininkuSkaiciuPardavusiuVirsKilogramu(int virskKiekPardaveBulviu) {
		int ukininkuSkaiciuPardavusiuVirsKilogramu = 0;
		for (Ukininkas ukininkas : ukininkai) {
			if (ukininkas.parduotosBulvesKilogramais > virskKiekPardaveBulviu)
				ukininkuSkaiciuPardavusiuVirsKilogramu++;
		}
		return ukininkuSkaiciuPardavusiuVirsKilogramu;
	}
};
void pildykDuomenis(UkininkuVienkryptisSarasas &ukininkai);

int main() {
	UkininkuVienkryptisSarasas ukininkai;
	pildykDuomenis(ukininkai);
	cout << "Kiek kilogramų bulviu buvo parduota is viso? - " << ukininkai.getParduotuBulviuKilogramaisSkaicius() << endl;
	cout << "Kiek uzfiksuota irasu, kai buvo parduota daugiau kaip 50 kg bulviu? - " << ukininkai.getUkininkuSkaiciuPardavusiuVirsKilogramu(50) << endl;
	cout << "Paskutinio ukinko parduotos bulves kg? - " << ukininkai.getPaskutinisUkininkas()->parduotosBulvesKilogramais << endl;
	system("pause");//TODO: remove
	return 0;
}
void pildykDuomenis(UkininkuVienkryptisSarasas &ukininkai) {
	ifstream ukininkuDuomenysStream("ObjektinisProgramavimas_KartUzd1_Duom.txt");
	int ukininkuKiekis;
	ukininkuDuomenysStream >> ukininkuKiekis;
	Ukininkas ukininkas;
	for (int i = 0; i < ukininkuKiekis; i++) {
		ukininkuDuomenysStream >> ukininkas.registracijosNumeris >> ukininkas.parduotosBulvesKilogramais;
		ukininkai.addUkininkas(ukininkas);
		ukininkai.add(ukininkas);
	}
	ukininkuDuomenysStream.close();
}