#include<iostream>
using namespace std;

int sumArray(int a[], int n, int k) {

    if(k == n - 1) return a[n-1];
    else return a[k] + sumArray(a, n, k + 1);
}

int sumArray1(int a[], int n, int k) {
    if(k == 0) return a[0];
    else return a[k] + sumArray1(a, n, k - 1);
}

int main() {

    int n;
    int a[100001];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << sumArray(a, n, 0) << endl;
    cout << sumArray1(a, n, n - 1);
}