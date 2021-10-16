//
//  main.cpp
//  LCS-vijos1111
//
//  Created by MickeyWu on 2021/10/13.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s1, s2;

#define MAXL 105
int dp[MAXL][MAXL];

#define same(i, j) (s1[i - 1] == s2[j - 1])

size_t LCS(size_t len1, size_t len2) {
    dp[0][0] = dp[1][0] = dp[0][1] = 0;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            dp[i][j] = max({dp[i - 1][j - 1] + same(i, j), dp[i - 1][j], dp[i][j - 1]});
    return len1 + len2 - dp[len1][len2];
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    while(cin >> s1 >> s2) cout << LCS(s1.size(), s2.size()) << endl;
    return 0;
}
