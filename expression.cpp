// luogu-7073 表达式
// Unaccepted 65分
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id, left, right, negate = 0;
} tree[1000010];
int curNode = 0;

#define MAXN 100010
int val[MAXN], ask[MAXN], res[MAXN];

typedef pair<int, vector<int> > retype;
retype dfs(int cur) {
    Node now = tree[cur];
    if (now.id > 0) return {val[now.id] ^ now.negate, {now.id}};
    retype ans, lp = dfs(now.left), rp = dfs(now.right);
    int flag = 0;
    if (now.id == -2) ans.first = rp.first & lp.first;
    else {
        ans.first = rp.first | lp.first;
        flag = 1;
    }
    bool lpp = false, rpp = false;
    int tmp = flag ^ 1;
    if (lp.second.empty() && !rp.second.empty()) rpp = lp.first == tmp;
    else if (!lp.second.empty() && rp.second.empty()) lpp = rp.first == tmp;
    else if (lp.first == rp.first) lpp = rpp = lp.first == tmp;
    else lpp = !(rpp = rp.first == flag);
    if (lpp) for (const int &i : lp.second) ans.second.push_back(i);
    if (rpp) for (const int &i : rp.second) ans.second.push_back(i);
    ans.first ^= now.negate;
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    string read;
    getline(cin, read);
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    cin >> q;
    for (int i = 1; i <= q; i++) cin >> ask[i];
    
    stack<int> exp;
    vector<int> num;
    for (const char &c: read) {
        if (isdigit(c)) num.push_back(c - '0');
        else if (c == ' ' && !num.empty()) {
            int ans = 0;
            int w = int(pow(10, num.size()));
            for (const int &i : num) ans += i * (w /= 10);
            num.resize(0);
            exp.push(ans);
        } else if (c == '|') exp.push(-1);
        else if (c == '&') exp.push(-2);
        else if (c == '!') exp.push(-3);
    }
    
    stack<int> rnod;
    int cur = 0, get;
    bool neg = 0;
    while (!exp.empty()) {
        get = exp.top();
        exp.pop();
        tree[cur].id = get;
        if (neg) {
            tree[cur].negate = 1;
            neg = false;
        }
        if (get < 0)
            if (get == -3) neg = true;
            else {
                tree[cur].left = ++curNode;
                tree[cur].right = ++curNode;
                rnod.push(tree[cur].right);
                cur = tree[cur].left;
            }
        else if (!rnod.empty()) {
            cur = rnod.top();
            rnod.pop();
        }
    }
    
    retype ret = dfs(0);
    for (const int &i : ret.second) res[i] = 1;
    for (int i = 1; i <= q; i++) cout << (ret.first ^ res[ask[i]]) << endl;
    return 0;
}
