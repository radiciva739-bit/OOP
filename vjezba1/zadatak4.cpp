#include <iostream>

int& at (int arr[], int i){
    return arr[i];
}

int main(){
    int niz[]={10,20,30,40,50};
    int n=sizeof(niz) / sizeof(niz[0]);

    int i=2;

    at(niz,i)+=5;

    for(int j=0; j<n; j++){
        std::cout << niz[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}