#include <iostream>
#include <iomanip>
#include <cstdlib>  
#include <ctime>    
using namespace std;

double** allocateMatrix(int m, int n) {
	double** matrix = new double*[m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new double[n];
	}
	return matrix;
}

void freeMatrix(double** matrix, int m) {
	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void inputMatrix(double** matrix, int m, int n) {
	cout << "Unesite elemente matrice (" << m << "x" << n << "):\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Element [" << i << "][" << j << "]: ";
			cin >> matrix[i][j];
		}
	}
}

void generateMatrix(double** matrix, int m, int n, double a, double b) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double r = ((double)rand() / RAND_MAX);  
			matrix[i][j] = a + r * (b - a);
		}
	}
}

void printMatrix(double** matrix, int m, int n) {
	cout << fixed << setprecision(4);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(10) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

double** addMatrices(double** m1, double** m2, int m, int n) {
	double** result = allocateMatrix(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			result[i][j] = m1[i][j] + m2[i][j];
	return result;
}

double** subtractMatrices(double** m1, double** m2, int m, int n) {
	double** result = allocateMatrix(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			result[i][j] = m1[i][j] - m2[i][j];
	return result;
}

double** multiplyMatrices(double** m1, int m, int p, double** m2, int n) {
	double** result = allocateMatrix(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = 0;
			for (int k = 0; k < p; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return result;
}

double** transposeMatrix(double** matrix, int m, int n) {
	double** transposed = allocateMatrix(n, m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			transposed[j][i] = matrix[i][j];
	return transposed;
}

int main() {
	srand(time(nullptr));  

	int m, n;
	cout << "Unesi broj redaka matrice: ";
	cin >> m;
	cout << "Unesi broj stupaca matrice: ";
	cin >> n;

	double** mat1 = allocateMatrix(m, n);
	inputMatrix(mat1, m, n);
	cout << "\nUnesena matrica:\n";
	printMatrix(mat1, m, n);

	double** mat2 = allocateMatrix(m, n);
	generateMatrix(mat2, m, n, 1.0, 10.0);
	cout << "\nGenerirana matrica:\n";
	printMatrix(mat2, m, n);

	double** sum = addMatrices(mat1, mat2, m, n);
	cout << "\nZbroj matrica:\n";
	printMatrix(sum, m, n);

	double** diff = subtractMatrices(mat1, mat2, m, n);
	cout << "\nRazlika matrica:\n";
	printMatrix(diff, m, n);

	double** mat3 = allocateMatrix(n, m);
	generateMatrix(mat3, n, m, 0.0, 5.0);

	cout << "\nMatrica za mnozenje (dimenzije " << n << " x " << m << "):\n";
	printMatrix(mat3, n, m);

	double** product = multiplyMatrices(mat1, m, n, mat3, m);
	cout << "\nProizvod matrica:\n";
	printMatrix(product, m, m);

	double** transposed = transposeMatrix(mat1, m, n);
	cout << "\nTransponirana matrica:\n";
	printMatrix(transposed, n, m);

	freeMatrix(mat1, m);
	freeMatrix(mat2, m);
	freeMatrix(sum, m);
	freeMatrix(diff, m);
	freeMatrix(mat3, n);
	freeMatrix(product, m);
	freeMatrix(transposed, n);

	return 0;
}
