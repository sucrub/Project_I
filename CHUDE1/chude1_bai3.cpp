#include<iostream>
using namespace std;

int countDigits(int num) {

    if(num < 10) return 1;
    else return 1 + countDigits(num / 10);
}

int main() {

    int n;
    cin >> n;
    cout << countDigits(n);
}