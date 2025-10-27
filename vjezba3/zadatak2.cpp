#include <iostream>
#include <cstddef> 
using namespace std;

template <typename T>
void sortt(T arr[], std::size_t n, bool(*cmp)(T, T)) {
	for (std::size_t i = 0; i < n - 1; i++) {
		for (std::size_t j = 0; j < n - i - 1; j++) {
			if (cmp(arr[j], arr[j + 1])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template <typename T>
inline bool ascending(T a, T b) {
	return a > b;  
}

template <typename T>
inline bool descending(T a, T b) {
	return a < b;  
}

template <typename T>
void printArray(T arr[], std::size_t n) {
	for (std::size_t i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arrInt[] = { 5, 2, 9, 1, 7 };
	std::size_t nInt = sizeof(arrInt) / sizeof(arrInt[0]);

	cout << "Pocetni int niz: ";
	printArray(arrInt, nInt);

	sortt(arrInt, nInt, ascending);
	cout << "Uzlazno sortiran int niz: ";
	printArray(arrInt, nInt);

	sortt(arrInt, nInt, descending);
	cout << "Silazno sortiran int niz: ";
	printArray(arrInt, nInt);

	cout << endl;

	double arrDouble[] = { 3.2, 1.5, 4.8, 2.1, 0.9 };
	std::size_t nDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);

	cout << "Pocetni double niz: ";
	printArray(arrDouble, nDouble);

	sortt(arrDouble, nDouble, ascending);
	cout << "Uzlazno sortiran double niz: ";
	printArray(arrDouble, nDouble);

	sortt(arrDouble, nDouble, descending);
	cout << "Silazno sortiran double niz: ";
	printArray(arrDouble, nDouble);

	return 0;
}
