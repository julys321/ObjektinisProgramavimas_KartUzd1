#pragma once
#include <string>
using namespace std;
class Bulves
{
public:
	string matavimoVienetas = "kilogramai";
	int kiekis;

	Bulves();
	Bulves(int kiekis) {
		this->kiekis = kiekis;
	}

	virtual ~Bulves();
};



Bulves::Bulves()
{
}


Bulves::~Bulves()
{
}
