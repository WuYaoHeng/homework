//
//  main.cpp
//  BIT
//
//  Created by MickeyWu on 2021/10/12.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define OJ_DEBUG true
#define $(x) {if (OJ_DEBUG) {cout << __LINE__ << ": "; {x} cout << endl;}}
#define _(x) {cout << #x << "=" << x << " ";}

#define MAXN int(5 * 1e5 + 10)
#define lowbit(x) ((x) & - (x))
int tree[MAXN];

int n, m;

void add(int x, int y) {
    while (x <= n) {
        tree[x] += y;
        x += lowbit(x);
    }
}

int sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int sum(int x, int y) {
    return sum(y) - sum(x - 1);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1, read; i <= n; i++) {
        cin >> read;
        add(i, read);
    }
    int opt, x, y;
    while (m--) {
        cin >> opt >> x >> y;
        if (opt == 1) add(x, y);
        else cout << sum(x, y) << endl;
    }
    return 0;
}
