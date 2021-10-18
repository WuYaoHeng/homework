//
//  main.cpp
//  Number-luogu7074
//
//  Created by MickeyWu on 2021/10/18.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;
#define INF (-1e18)
#define MAXN 1010
ll n, m, gra[MAXN][MAXN], dp[MAXN][MAXN][3];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> gra[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = INF;
        }
    
    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = gra[1][1];
    for (int i = 2; i <= n; i++) dp[i][1][1] = dp[i - 1][1][1] + gra[i][1];
    for (int j = 2; j <= m; j++) {
        for (int i = 1; i <= n; i++)
            dp[i][j][0] = max({dp[i][j - 1][0], dp[i][j - 1][1], dp[i][j - 1][2]}) + gra[i][j];
        for (int i = 2; i <= n; i++)
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0]) + gra[i][j];
        for (ll i = n - 1; i >= 1; i--)
            dp[i][j][2] = max(dp[i + 1][j][2], dp[i + 1][j][0]) + gra[i][j];
    }
    cout << max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    return 0;
}

