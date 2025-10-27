#include <iostream>
#include <string>
#include <cstddef> 
using namespace std;

struct Student {
	string ime;
	string jmbag;
	int godina;
	int ects;
	double prosjek;
};

void filter_students(Student studenti[], std::size_t n,
	void(*akcija)(Student&),
	bool(*filter)(Student&))
{
	for (std::size_t i = 0; i < n; i++) {
		if (filter(studenti[i])) {
			akcija(studenti[i]);
		}
	}
}

void ispisi_studenta(Student &s) {
	cout << "Ime: " << s.ime
		<< ", JMBAG: " << s.jmbag
		<< ", Godina: " << s.godina
		<< ", ECTS: " << s.ects
		<< ", Prosjek: " << s.prosjek
		<< endl;
}

void povecaj_godinu(Student &s) {
	s.godina++;
	cout << s.ime << " je sada na " << s.godina << ". godini studija." << endl;
}

int main() {
	Student studenti[] = {
		{"Ana Horvat", "001", 1, 30, 4.2},
		{"Ivan Kovač", "002", 1, 0, 3.0},
		{"Maja Perić", "003", 2, 45, 3.8},
		{"Luka Marić", "004", 3, 60, 2.9},
		{"Petra Novak", "005", 1, 50, 4.5}
	};
	std::size_t n = sizeof(studenti) / sizeof(studenti[0]);

	cout << "-------------------------------------------\n";
	cout << "1️ Studenti prve godine koji su polozili barem jedan ispit:\n";
	auto uvjet1 = [](Student &s) { return s.godina == 1 && s.ects > 0; };
	filter_students(studenti, n, ispisi_studenta, uvjet1);

	cout << "-------------------------------------------\n";
	cout << "2️ Studenti s prosjekom vecim od 3.5:\n";
	auto uvjet2 = [](Student &s) { return s.prosjek > 3.5; };
	filter_students(studenti, n, ispisi_studenta, uvjet2);

	cout << "-------------------------------------------\n";
	cout << "3️ Povecanje godine studija studentima s barem 45 ECTS bodova:\n";
	auto uvjet3 = [](Student &s) { return s.ects >= 45; };
	filter_students(studenti, n, povecaj_godinu, uvjet3);

	return 0;
}
