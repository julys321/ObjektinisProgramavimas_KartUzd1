#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Ukininkas {
	char registracijosNumeris[3];
	long int parduotosBulvesKilogramais;
};
struct Ukininkai {
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
void pildykDuomenis(Ukininkai &ukininkai);
int main() {
	Ukininkai ukininkai;
	pildykDuomenis(ukininkai);
	cout << "Kiek kilogramų bulviu buvo parduota is viso? - " << ukininkai.getParduotuBulviuKilogramaisSkaicius() << endl;
	cout << "Kiek uzfiksuota irasu, kai buvo parduota daugiau kaip 50 kg bulviu? - " << ukininkai.getUkininkuSkaiciuPardavusiuVirsKilogramu(50) << endl;
	system("pause");//TODO: remove
	return 0;
}
void pildykDuomenis(Ukininkai &ukininkai) {
	ifstream ukininkuDuomenysStream("ObjektinisProgramavimas_KartUzd1_Duom.txt");
	int ukininkuKiekis;
	ukininkuDuomenysStream >> ukininkuKiekis;
	Ukininkas ukininkas;
	for (int i = 0; i < ukininkuKiekis; i++) {
		ukininkuDuomenysStream >> ukininkas.registracijosNumeris >> ukininkas.parduotosBulvesKilogramais;
		ukininkai.addUkininkas(ukininkas);
	}
	ukininkuDuomenysStream.close();
}