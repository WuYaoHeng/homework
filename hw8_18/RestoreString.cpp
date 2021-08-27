// vijos的训练计划 章节2 1449

#include <iostream>
#include <algorithm>
using namespace std;

int dis(char c1, char c2) {
    char big = max(c1, c2), small = min(c1, c2);
    return min(big - small - 1, 'z' - big + small - 'a');
}

bool judge(const string &s1, const string &s2, const string &s3, int len) {
    bool ans = true;
    string s = s3;
    reverse(s.begin(), s.end());
    for (int i = 0; i < len; ++i) {
        if (s1[i] == s2[i] && s1[i] != s[i] || dis(s1[i], s[i]) != dis(s2[i], s[i])) {
            ans = false;
            break;
        }
    }
    if (ans) cout << s;
    return ans;
}

int main() {
    int n;
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (!judge(s1, s2, s3, n)) if (!judge(s1, s3, s2, n)) {
        reverse(s1.begin(), s1.end());
        cout << s1;
    }
    return 0;
}
