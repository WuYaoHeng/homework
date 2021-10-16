//
//  main.cpp
//  Incantation-vijos1264
//
//  Created by MickeyWu on 2021/10/13.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXM 505
int dp[MAXM];
int r1[MAXM], r2[MAXM];

int m1, m2;

int LIS_LCS() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m1; i++) {
        int maxn = 0;
        for (int j = 1; j <= m2; j++) {
            if (r1[i - 1] > r2[j - 1]) maxn = max(maxn, dp[j]);
            else if (r1[i - 1] == r2[j - 1]) dp[j] = max(dp[j], maxn + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m2; i++) ans = max(ans, dp[i]);
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        cin >> m1;
        for (int i = 0; i < m1; i++) cin >> r1[i];
        cin >> m2;
        for (int i = 0; i < m2; i++) cin >> r2[i];
        cout << LIS_LCS() << endl;
    }
    return 0;
}
