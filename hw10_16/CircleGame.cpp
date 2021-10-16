//
//  main.cpp
//  CircleGame-vijos1841
//
//  Created by MickeyWu on 2021/10/14.
//

#include <iostream>
#include <algorithm>
using namespace std;

int binpow(int a, int b, int n) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    cout << (x + m * binpow(10, k, n)) % n;
    return 0;
}
