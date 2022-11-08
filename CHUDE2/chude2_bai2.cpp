#include<iostream>
using namespace std;

int hornerMethod(int a[], int n, int x) {
    
    int result = a[n];
    for(int i = n-1; i  >= 0; i--) {
        result = result * x + a[i];
    }
    return result;
}

int main() {

    int n;
    int x;
    int a[100001];

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap x: ";
    cin >> x;
    for(int i = 0; i <= n; i++) {
        cout << "Nhap a" << i << ": ";
        cin >> a[i];
    }
    cout << hornerMethod(a, n, x);
    
}