//10.5 
//luogu p7073
//Unaccepted 45分

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int id, left, right, val;
    bool negate = false;
};
Node tree[1000005];
int curNode = 0;
#define left(i) ((i) * 2 + 1)
#define right(i) (left(i) + 1)
string read;
int n, q;
int val[100005], ask[100005];

pair<int, vector<int> > dfs(int cur) {
    Node &now = tree[cur];
    if (now.id > 0) return {now.val ^ now.negate, {now.id}};
    auto lp = dfs(now.left), rp = dfs(now.right);
    vector<int> ans;
    int flag = 0;
    if (now.id == -2)
        now.val = rp.first & lp.first;
    else {
        now.val = rp.first | lp.first;
        flag = 1;
    }
    if (lp.second.empty() && rp.second.empty());
    else if (lp.second.empty() && !rp.second.empty() && lp.first == !flag)
        for (const int &i : rp.second) ans.push_back(i);
    else if (rp.second.empty() && !lp.second.empty() && rp.first == !flag)
        for (const int &i : lp.second) ans.push_back(i);
    else if (lp.first != rp.first) {
        if (lp.first == flag)
            for (const int &i : lp.second) ans.push_back(i);
        else
            for (const int &i : rp.second) ans.push_back(i);
    } else if (lp.first == ~flag) {
        for (const int &i : rp.second) ans.push_back(i);
        for (const int &i : lp.second) ans.push_back(i);
    }
    return {now.val ^ now.negate, ans};
}
bool res[100005];
int main(int argc, const char * argv[]) {
    getline(cin, read);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i];
    cin >> q;
    for (int i = 0; i < q; i++) cin >> ask[i];
    stack<int> exp;
    vector<int> tmp;
    for (const char &c: read) {
        if (isdigit(c)) tmp.push_back(c - '0');
        else if (c == ' ' && !tmp.empty()) {
            int num = 0;
            int w = int(pow(10, tmp.size()));
            for (const int &i : tmp) num += i * (w /= 10);
            tmp.clear();
            exp.push(num);
        } else if (c == '|') exp.push(-1);
        else if (c == '&') exp.push(-2);
        else if (c == '!') exp.push(-3);
    }
    stack<int> nod;
    int cur = 0, get;
    bool negate = false;
    while (!exp.empty()) {
        get = exp.top();
        exp.pop();
        tree[cur].id = get;
        if (negate) {
            tree[cur].negate = true;
            negate = false;
        }
        if (get < 0) {
            if (get != -3) {
                tree[cur].left = ++curNode;
                tree[cur].right = ++curNode;
                nod.push(tree[cur].right);
                cur = tree[cur].left;
            } else negate = true;
        } else {
            tree[cur].val = val[get - 1];
            if (!nod.empty()) {
                cur = nod.top();
                nod.pop();
            }
        }
    }
    auto a = dfs(0);
    for (const int &i : a.second) res[i] = true;
    for (int i = 0; i < q; i++) cout << (a.first ^ res[ask[i]]) << endl;
    return 0;
}
