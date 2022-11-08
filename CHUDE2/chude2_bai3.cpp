#include<iostream>
#include<string>
using namespace std;

int main() {

    string s1, s2, s3;
    int m, n;
    int a[100001], b[100001], c[100001] = {0};
    cin >> m;
    for(int i = 0; i <= m; i++) {
        cin >> a[i];
    }
    s1 += to_string(a[0]);
    for(int i = 1; i <= m; i++) {
        s1 += " + ";
        s1 += to_string(a[i]);
        s1 += "x^";
        s1 += to_string(i);
    }
    cin >> n;
    for(int i = 0; i <= n; i++) {
        cin >> b[i];
    }
    s2 += to_string(b[0]);
    for(int i = 1; i <= n; i++) {
        s2 += " + ";
        s2 += to_string(b[i]);
        s2 += "x^";
        s2 += to_string(i);
    }
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    s3 += to_string(c[0]);
    for(int i = 1; i <= m + n; i++) {
        s3 += " + ";
        s3 += to_string(c[i]);
        s3 += "x^";
        s3 += to_string(i);
    }

    cout << "Da thuc thu nhat: " << s1 << endl;
    cout << "Da thuc thu hai: " << s2 << endl;
    cout << "Tich da thuc: " << s3 << endl;
}