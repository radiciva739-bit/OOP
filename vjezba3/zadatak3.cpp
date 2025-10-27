#include <iostream>
#include <vector>
#include <cstddef> 
using namespace std;

int main() {
	auto parni = [](int x) { return x % 2 == 0; };
	auto neparni = [](int x) { return x % 2 != 0; };

	auto udvostruci = [](int x) { return x * 2; };
	auto prepolovi = [](int x) { return x / 2; };

	int suma = 0;
	int produkt = 1;
	auto dodajUSumu = [&](int x) { suma += x; };
	auto dodajUProdukt = [&](int x) { produkt *= x; };

	int prag = 5;
	int s = 0;
	auto dodajAkoVeciOdPraga = [prag, &s](int x) {
		if (x > prag) s += x;
	};
	vector<int> niz = { 2, 5, 8, 3, 10 };

	cout << "Pocetni niz: ";
	for (int x : niz) cout << x << " ";
	cout << endl;

	for (int &x : niz) {
		if (parni(x))
			x = prepolovi(x);
		else
			x = udvostruci(x);
	}

	cout << "Nakon transformacije (parni prepolovljeni, neparni udvostruceni): ";
	for (int x : niz) cout << x << " ";
	cout << endl;

	for (int x : niz) {
		dodajUSumu(x);
		dodajUProdukt(x);
	}

	cout << "Suma clanova niza: " << suma << endl;
	cout << "Produkt clanova niza: " << produkt << endl;

	for (int x : niz) {
		dodajAkoVeciOdPraga(x);
	}

	cout << "Suma brojeva vecih od " << prag << " je: " << s << endl;

	return 0;
}
