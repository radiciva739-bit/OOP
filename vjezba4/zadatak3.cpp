#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

void fix_spaces(string& text) {
	for (size_t i = 0; i < text.size() - 1; ) {
		if (text[i] == ' ' && text[i + 1] == ' ') {
			text.erase(i, 1); 
		}
		else {
			i++;
		}
	}

	for (size_t i = 0; i < text.size(); i++) {
		if ((text[i] == ',' || text[i] == '.') && i > 0 && text[i - 1] == ' ') {
			text.erase(i - 1, 1);
			i--; 
		}
	}

	for (size_t i = 0; i < text.size(); i++) {
		if (text[i] == ',' && (i + 1 < text.size()) && text[i + 1] != ' ') {
			text.insert(i + 1, " ");
		}
	}
}

int main() {
	string s = "Puno   razmaka ,i tocka .";
	cout << "Prije:  \"" << s << "\"" << endl;

	fix_spaces(s);

	cout << "Poslije: \"" << s << "\"" << endl;

	return 0;
}
