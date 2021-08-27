// vijos的训练计划 章节2 1217

#include <iostream>
#include <vector>
using namespace std;

void settlement(vector<pair<int, int>> &a, int &w, int &l, int s) {
    int big = w, small = l;
    if (w < l) swap(big, small);
    if (big >= s && big - small > 1) {
        a.emplace_back(w, l);
        w = l = 0;
    }
}

void print(vector<pair<int, int>> &a) {
    for (pair<int, int> i : a) cout << i.first << ":" << i.second << endl;
}

int main() {
    vector<pair<int, int>> a11, a21;

    char c;
    int w1 = 0, w2 = 0;
    int l1 = 0, l2 = 0;

    while (true) {
        cin >> c;

        if (c == 'E') {
            a11.emplace_back(w1, l1);
            a21.emplace_back(w2, l2);
            break;
        }
        else if (c == 'W') w1++, w2++;
        else if (c == 'L') l1++, l2++;

        settlement(a11, w1, l1, 11);
        settlement(a21, w2, l2, 21);
    }

    print(a11);
    cout << endl;
    print(a21);

    return 0;
}
