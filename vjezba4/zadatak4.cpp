#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

string word_to_pig_latin(const string& word) {
	if (word.empty()) return ""; 

	string vowels = "aeiouAEIOU";

	if (vowels.find(word[0]) != string::npos) {
		return word + "hay";
	}
	else {
		string pig = word.substr(1) + word[0] + "ay";
		return pig;
	}
}

int main() {
	cout << word_to_pig_latin("apple") << endl; 
	cout << word_to_pig_latin("hello") << endl; 
	cout << word_to_pig_latin("OpenAI") << endl; 
	cout << word_to_pig_latin("World") << endl; 
	return 0;
}
