#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            a[i][j] = (j == 0 || j == i ? 1 : a[i - 1][j - 1] + a[i - 1][j]);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
