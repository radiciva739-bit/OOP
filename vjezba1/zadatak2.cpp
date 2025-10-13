#include "pch.h"
#include <iostream>
using namespace std;

int ogranicenje(int vrijednost, int low = 0, int high = 100) {
	if (vrijednost < low) {
		return low;
	}
	else if (vrijednost > high) {
		return high;
	}
	return vrijednost;
}

double ogranicenje(double vrijednost, double low = 0.0, double high = 100.0) {
	if (vrijednost < low) {
		return low;
	}
	else if (vrijednost > high) {
		return high;
	}
	return vrijednost;
}

int main() {
	cout << "Testiranje funkcije za int:" << endl;
	cout << "Vrijednost 150 unutar intervala [0, 100]: " << ogranicenje(150) << endl;  
	cout << "Vrijednost -10 unutar intervala [0, 100]: " << ogranicenje(-10) << endl;   
	cout << "Vrijednost 50 unutar intervala [0, 100]: " << ogranicenje(50) << endl;     

	cout << "\nTestiranje funkcije za double:" << endl;
	cout << "Vrijednost 150.5 unutar intervala [0.0, 100.0]: " << ogranicenje(150.5) << endl; 
	cout << "Vrijednost -10.5 unutar intervala [0.0, 100.0]: " << ogranicenje(-10.5) << endl;
	cout << "Vrijednost 50.25 unutar intervala [0.0, 100.0]: " << ogranicenje(50.25) << endl; 

	return 0;
}

