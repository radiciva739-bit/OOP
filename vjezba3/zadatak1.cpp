#include <iostream>
#include <cstddef> 
using namespace std;

inline bool ascending(int a, int b) {
	return a > b; 
}

inline bool descending(int a, int b) {
	return a < b;  
}

void sortt(int arr[], std::size_t n, bool(*cmp)(int, int)) {
	for (std::size_t i = 0; i < n - 1; i++) {
		for (std::size_t j = 0; j < n - i - 1; j++) {
			if (cmp(arr[j], arr[j + 1])) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printArray(int arr[], std::size_t n) {
	for (std::size_t i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 5, 2, 9, 1, 7 };
	std::size_t n = sizeof(arr) / sizeof(arr[0]);

	cout << "Pocetni niz: ";
	printArray(arr, n);

	sortt(arr, n, ascending);
	cout << "Uzlazno sortiran niz: ";
	printArray(arr, n);

	sortt(arr, n, descending);
	cout << "Silazno sortiran niz: ";
	printArray(arr, n);

	return 0;
}
