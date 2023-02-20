#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

// int convertStep(string s1, string s2, int m, int n) {

//     if (s1 == s2) return 0;
//     if (m == 0) return n;
//     if (n == 0) return m;
//     if(s1[m - 1] == s2[n - 1]) return convertStep(s1, s2, m - 1, n - 1);
//     return 1 + min(convertStep(s1, s2, m-1, n-1),
//     min(convertStep(s1, s2, m, n-1), convertStep(s1, s2, m-1, n)));
// }

// int convertStepTestingNotOffical2(string s1, string s2, int m, int n) {

//     int dp[m+1][n+1];
//     for(int i = 0; i <= m; i++) {
//         for(int j = 0; j <= n; j++) {
//             if(i == 0) dp[0][j] = j;
//             else if(j == 0) dp[i][j] = i;
//             else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
//             else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j-1], dp[i-1][j]));
//         }
//     }
//     return dp[m][n];
// }

int convertStep(string s1, string s2, int m, int n, vector<vector<int> > &dp) {

    if(m == 0) return n;
    if(n == 0) return m;
    if(dp[m][n] != -1) return dp[m][n];
    if(s1[m - 1] == s2[n - 1]) return dp[m][n] = convertStep(s1, s2, m-1, n-1, dp);
    else {
        int insert, del, replace;
        insert = convertStep(s1, s2, m, n-1, dp);
        del = convertStep(s1, s2, m-1, n, dp);
        replace = convertStep(s1, s2, m-1, n-1, dp);
        return dp[m][n] = 1 + min(insert, min(replace, del));
    }

}

int main() {

    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    //dp la vector co m+1 phan tu, moi phan tu la 1 vector khac co n+1 gia tri -1 --> ma tran m+1 x n+1
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1)); 
    cout << convertStep(s1, s2, m, n, dp);
}