//
//  main.cpp
//  LinearEquations-luogu3389
//
//  Created by MickeyWu on 2021/10/8.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 105
double mat[MAXN][MAXN];
int n;

/*
 3
 1 2 8 6
 3 1 6 2
 9 1 2 5
 */

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) printf("%lf ", mat[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void sub(int row1, int row2, double mul) {
    bool err = true;
    for (int i = 0; i <= n; i++) {
        mat[row1][i] -= mat[row2][i] * mul;
        if (mat[row1][i] != 0) err = false;
    }
    if (err) {
        printf("No Solution");
        exit(0);
    }
}

void lad(int cur) {
    if (cur == n) return;
    for (int i = cur + 1; i <= n; i++) mat[cur][i] /= mat[cur][cur];
    mat[cur][cur] = 1;
    for (int i = cur + 1; i < n; i++)
        sub(i, cur, mat[i][cur] / mat[cur][cur]);
    lad(++cur);
}

void uni(int cur) {
    if (cur == 0) return;
    for (int i = cur - 1; i >= 0; i--) {
        mat[i][n] -= mat[i][cur] * mat[cur][n];
        mat[i][cur] = 0;
    }
//    print();
    uni(--cur);
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%lf", mat[i] + j);

    lad(0);
    uni(n - 1);
    for (int i = 0; i < n; i++) printf("%.2lf\n", mat[i][n]);

    return 0;
}
