//
//  main.cpp
//  SmallStick-luogu1120
//
//  Created by MickeyWu on 2021/10/15.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define MAXN 70
int n, a[MAXN], vis[MAXN];
int sum, m;

void dfs(int t, int s, int beg) {
    if (t == 0) {
        cout << m;
        exit(0);
    } else if (s == m) {
        dfs(t - 1, 0, 1);
        return;
    }
    for (int i = beg; i <= n; i++) if (!vis[i] && s + a[i] <= m) {
        vis[i] = true;
        dfs(t, s + a[i], i + 1);
        vis[i] = false;
        if (s == 0 || s + a[i] == m) break;
        while (a[i] == a[i + 1]) i++;
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; sum += a[i], i++) cin >> a[i];
    sort(a + 1, a + n + 1, [](int a, int b) {return a > b;});
    int mid = sum >> 1;
    for (m = a[n]; m <= mid; m++) if (sum % m == 0) dfs(sum / m, 0, 1);
    cout << sum;
    return 0;
}
