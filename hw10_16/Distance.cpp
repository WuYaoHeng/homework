//
//  main.cpp
//  Distance-vijos1680
//
//  Created by MickeyWu on 2021/10/13.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXL 2005
int dp[MAXL][MAXL];
string s1, s2;
int k;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> s1 >> s2 >> k;
    int len1 = (int)s1.size(), len2 = (int)s2.size();
    for (int i = 0; i <= len1; i++) dp[i][0] = i * k;
    for (int i = 0; i <= len2; i++) dp[0][i] = i * k;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + k, dp[i - 1][j - 1] + abs(s1[i - 1] - s2[j - 1]));
    cout << dp[len1][len2];
    return 0;
}
