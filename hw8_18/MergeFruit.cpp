// vijos 1097

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long tmp;

    if (n == 1) {
        cin >> tmp;
        cout << tmp;
        return 0;
    }

    priority_queue<long long, vector<long long>, greater<long long>> p;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        p.push(tmp);
    }

    long long sum = 0;
    long long s1, s2, s3;
    for (int i = 0; i < n; ++i) {
        s1 = p.top();
        p.pop();
        s2 = p.top();
        p.pop();
        sum += (s3 = s1 + s2);
        if (p.empty()) break;
        p.push(s3);
    }
    cout << sum;
    return 0;
}
