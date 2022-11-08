#include<iostream>
using namespace std;

void input(int matrix[100][100], int m, int n) {

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void output(int matrix[100][100], int m, int n) {

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void sumOfMatrix(int A[100][100], int B[100][100], int C[100][100], int m, int n) {

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    output(C, m, n);
}

int main() {

    int m, n;
    int A[100][100], B[100][100], C[100][100];
    cin >> m >> n;
    input(A, m, n);
    input(B, m, n);
    sumOfMatrix(A, B, C, m, n);
}