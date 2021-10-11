//
//  main.cpp
//  CoinGame - vijos1554
//
//  Created by MickeyWu on 2021/10/10.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

#define MAXN 100010
int n;
long long T;

struct Mat {
    vector<bool> data = vector<bool>(MAXN, 0);
    
    void print() const {
        for (int i = 0 ; i < n; i++) _(data[i]);
        cout << endl;
    }
    
    friend Mat operator *(const Mat& m1, const Mat& m2) {
        Mat ans;
        for (int i = 0, j = 0, s = 0; i < n; i++, s = j = 0) {
            for (int k = i; k >= 0; k--) s += m1.data[j++] * m2.data[k];
            for (int k = n - 1; k > i; k--) s += m1.data[j++] * m2.data[k];
            ans.data[i] = s % 2;
        }
        return ans;
    }
} unit[2], in;

void init() {
    unit[0].data[0] = unit[0].data[1] = unit[1].data[0] = unit[1].data[n - 1] = 1;
}

Mat binpow() {
    init();
    Mat ans;
    ans.data[0] = 1;
    Mat base = unit[0] * unit[1];
    bool need = T & 1;
    T >>= 1;
    while (T > 0) {
        if (T & 1) ans = ans * base;
        base = base * base;
        T >>= 1;
    }
    if (need) ans = ans * unit[0];
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> T;
    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        in.data[i] = tmp - 1;
    }
    bool fro0 = T & 1;
    Mat ans = binpow();
    for (int i = 0, j = 0, s = 0; i < n; i++, j = s = 0) {
        for (int k = n - i; k < n; k++) s += ans.data[k] * in.data[j++];
        for (int k = 0; k < n - i; k++) s += ans.data[k] * in.data[j++];
        if (fro0) cout << "0 " << s % 2 + 1 << " ";
        else cout << s % 2 + 1 << " 0 ";
    }
    cout << endl;
    return 0;
}
