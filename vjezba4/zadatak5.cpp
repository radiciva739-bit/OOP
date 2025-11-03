#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

void reverse_strings(vector<string>& words) {
	for (int i = 0; i < words.size(); i++) {
		reverse(words[i].begin(), words[i].end());
	}
}

void print_vector(const vector<string>& words) {
	cout << "[";
	for (int i = 0; i < words.size(); i++) {
		cout << "\"" << words[i] << "\"";
		if (i < words.size() - 1) cout << ", ";
	}
	cout << "]" << endl;
}

int main() {
	vector<string> rijeci = { "hello", "world", "c++" };

	cout << "Prije okretanja: ";
	print_vector(rijeci);

	reverse_strings(rijeci);

	cout << "Nakon okretanja: ";
	print_vector(rijeci);

	return 0;
}
