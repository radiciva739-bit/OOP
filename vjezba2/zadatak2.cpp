#include <iostream>
using namespace std;

struct Vector {
	int* data;         
	int logicalSize;   
	int physicalSize;   
};

Vector vector_new(int init) {
	Vector v;
	v.data = new int[init];
	v.logicalSize = 0;
	v.physicalSize = init;
	return v;
}

void vector_delete(Vector& v) {
	delete[] v.data;
	v.data = nullptr;
	v.logicalSize = 0;
	v.physicalSize = 0;
}

void vector_push_back(Vector& v, int value) {
	if (v.logicalSize == v.physicalSize) {
		int* newData = new int[v.physicalSize * 2];
		for (int i = 0; i < v.logicalSize; i++) {
			newData[i] = v.data[i];
		}
		delete[] v.data;
		v.data = newData;
		v.physicalSize *= 2;
	}
	v.data[v.logicalSize] = value;
	v.logicalSize++;
}

void vector_pop_back(Vector& v) {
	if (v.logicalSize > 0) {
		v.logicalSize--;
	}
}

int vector_front(const Vector& v) {
	if (v.logicalSize > 0) {
		return v.data[0];
	}
	cerr << "Vector is empty!" << endl;
	return -1;
}

int vector_back(const Vector& v) {
	if (v.logicalSize > 0) {
		return v.data[v.logicalSize - 1];
	}
	cerr << "Vector is empty!" << endl;
	return -1;
}

int vector_size(const Vector& v) {
	return v.logicalSize;
}

int main() {
	Vector v = vector_new(2);

	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30); 

	cout << "Prvi element: " << vector_front(v) << endl;
	cout << "Zadnji element: " << vector_back(v) << endl;
	cout << "Velicina vektora: " << vector_size(v) << endl;

	cout << "Svi elementi: ";
	for (int i = 0; i < vector_size(v); i++) {
		cout << v.data[i] << " ";
	}
	cout << endl;

	vector_pop_back(v);

	cout << "Nakon uklanjanja zadnjeg elementa: ";
	for (int i = 0; i < vector_size(v); i++) {
		cout << v.data[i] << " ";
	}
	cout << endl;

	vector_delete(v);

	return 0;
}
