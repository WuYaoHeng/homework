//
//  main.cpp
//  MissileInterception-vijos1303
//
//  Created by MickeyWu on 2021/10/13.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

#define MAXN 23
int pos = 0;
int hei[MAXN], dp[MAXN];
vector<int> v;

void getInt() {
    int ans = 0, w = pow(10, v.size());
    for (const int& j : v) ans += j * (w /= 10);
    hei[pos++] = ans;
    v.clear();
}

static int LIS(int up) {
    int ans = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= pos; i++) {
        for (int j = i - 1; j >= 0; j--)
            if (up ^ (hei[i] <= hei[j])) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    for (const char& i : s)
        if (i == ',') getInt();
        else v.push_back(i - '0');
    getInt();
    cout << LIS(0) << "," << LIS(1);
    return 0;
}
