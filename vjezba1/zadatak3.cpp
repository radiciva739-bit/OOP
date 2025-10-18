#include <iostream>
#include <string>
#include <cctype>

int main(){
    std::cout << "Unesi nešto:" << std::endl;
    std::string s;
    std::getline(std::cin, s);

    for(char& ch : s){
        if (std::isalpha(ch)){
            ch = std::toupper(ch);
        }
        else if(std::isdigit(ch)){
            ch ='*';
        }
        else if(ch=='' || ch=='\t'){
            ch='_';
        }
    }

    std::cout << s << '\n';
    return 0;
}