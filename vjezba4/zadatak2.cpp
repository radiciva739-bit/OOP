#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>    
using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unesite brojeve (0 za kraj): ";
	while (true) {
		cin >> broj;
		if (broj == 0) break;
		v.push_back(broj);
	}
}

void print_vector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i < v.size() - 1) cout << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v;
	input_vector(v);

	cout << "Originalni vektor: ";
	print_vector(v);

	vector<int> jedinstveni;
	for (int i = 0; i < v.size(); i++) {
		if (find(jedinstveni.begin(), jedinstveni.end(), v[i]) == jedinstveni.end()) {
			jedinstveni.push_back(v[i]);
		}
	}

	cout << "Jedinstveni elementi: ";
	print_vector(jedinstveni);

	sort(jedinstveni.begin(), jedinstveni.end(), [](int a, int b) {
		return abs(a) < abs(b);
	});

	cout << "Sortirani po apsolutnoj vrijednosti: ";
	for (int i = 0; i < jedinstveni.size(); i++) {
		cout << jedinstveni[i];
		if (i < jedinstveni.size() - 1) cout << ", ";
	}
	cout << endl;

	cout << "Elementi i njihove apsolutne vrijednosti:" << endl;
	for (int i = 0; i < jedinstveni.size(); i++) {
		cout << jedinstveni[i] << " (|" << abs(jedinstveni[i]) << "|)" << endl;
	}

	return 0;
}
