#include <iostream>
#include <vector>
using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unesite brojeve (0 za kraj): ";
	while (true) {
		cin >> broj;
		if (broj == 0)  
			break;
		v.push_back(broj);
	}
}

void print_vector(const vector<int>& v) {
	cout << "Elementi vektora su: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> brojevi;
	input_vector(brojevi);
	print_vector(brojevi);
	return 0;
}
