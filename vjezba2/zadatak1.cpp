#include <iostream>
using namespace std;

int* fibonacci(int n) {
	int* niz = new int[n];
	if (n >= 1) niz[0] = 1;
	if (n >= 2) niz[1] = 1;

	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}
	return niz;
}

int main() {
	int n;
	cout << "Unesi velicinu niza: ";
	cin >> n;

	int* fibNiz = fibonacci(n);

	cout << "Fibonacci niz: ";
	for (int i = 0; i < n; i++) {
		cout << fibNiz[i] << " ";
	}
	cout << endl;

	delete[] fibNiz;

	return 0;
}
