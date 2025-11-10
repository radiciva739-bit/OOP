#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Karta {
public:
	string zog; 
	int broj;   

	Karta(string z = "", int b = 0) {
		zog = z;
		broj = b;
	}

	void ispisi() const {
		cout << broj << " " << zog;
	}
};

class Mac {
public:
	vector<Karta> karte;

	Mac() {
		string zogovi[4] = { "kupa", "dinari", "spade", "bastuni" };
		for (int i = 0; i < 4; i++) {
			for (int broj = 1; broj <= 10; broj++) {
				karte.push_back(Karta(zogovi[i], broj));
			}
		}
	}

	void promijesaj() {
		srand(time(0));
		random_shuffle(karte.begin(), karte.end());
	}

	vector<Karta> podijeli() {
		vector<Karta> ruka;
		for (int i = 0; i < 10; i++) {
			ruka.push_back(karte.back());
			karte.pop_back();
		}
		return ruka;
	}
};

class Igrac {
public:
	string ime;
	vector<Karta> ruka;
	int bodovi;

	Igrac(string i = "") {
		ime = i;
		bodovi = 0;
	}

	void primiKarte(vector<Karta> noveKarte) {
		ruka = noveKarte;
	}

	void ispisiRuku() const {
		cout << "Karte igraca " << ime << ": ";
		for (auto &k : ruka) {
			cout << "[" << k.broj << " " << k.zog << "] ";
		}
		cout << endl;
	}

	void izracunajAkuze() {
		bodovi = 0;

		string zogovi[4] = { "kupa", "dinari", "spade", "bastuni" };
		for (int i = 0; i < 4; i++) {
			bool imaAs = false, imaDva = false, imaTri = false;
			for (auto &k : ruka) {
				if (k.zog == zogovi[i]) {
					if (k.broj == 1) imaAs = true;
					if (k.broj == 2) imaDva = true;
					if (k.broj == 3) imaTri = true;
				}
			}
			if (imaAs && imaDva && imaTri) {
				bodovi += 3;
			}
		}

		int brojevi[3] = { 1, 2, 3 };
		for (int i = 0; i < 3; i++) {
			int count = 0;
			for (auto &k : ruka) {
				if (k.broj == brojevi[i])
					count++;
			}
			if (count == 3)
				bodovi += 3;
			else if (count == 4)
				bodovi += 4;
		}
	}
};

int main() {
	int brojIgraca;
	cout << "Unesite broj igraca (2 ili 4): ";
	cin >> brojIgraca;

	while (brojIgraca != 2 && brojIgraca != 4) {
		cout << "Mozete igrati samo s 2 ili 4 igraca. Pokusajte ponovo: ";
		cin >> brojIgraca;
	}

	vector<Igrac> igraci;
	for (int i = 0; i < brojIgraca; i++) {
		string ime;
		cout << "Unesite ime igraca " << i + 1 << ": ";
		cin >> ime;
		igraci.push_back(Igrac(ime));
	}

	Mac mac;
	mac.promijesaj();

	for (int i = 0; i < brojIgraca; i++) {
		igraci[i].primiKarte(mac.podijeli());
	}

	cout << "\n=== Karte igraca ===\n";
	for (int i = 0; i < brojIgraca; i++) {
		igraci[i].ispisiRuku();
	}

	cout << "\n=== Akuze ===\n";
	for (int i = 0; i < brojIgraca; i++) {
		igraci[i].izracunajAkuze();
		cout << igraci[i].ime << " ima " << igraci[i].bodovi << " bodova iz akuze.\n";
	}

	return 0;
}
