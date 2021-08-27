// vijos 1828

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
//
//struct Tree {
//    map<char, Tree *> letters;
//    bool isWord = false;
//
//    void add(string &s) {
//        Tree *cur = this;
//        for (char i : s) {
//            auto tmp = cur->letters.find(i);
//            if (tmp != cur->letters.end()) {
//                cur = tmp->second;
//            } else {
//                Tree *t = new Tree();
//                cur->letters.insert(pair<char, Tree *>(i, t));
//                cur = t;
//            }
//        }
//        cur->isWord = true;
//    }
//    void print();
//};
//
//int t = 0;
//int b = 0;
//
//void dfs(Tree *cur, int n) {
//    if (cur->isWord) {
////        cout << endl;
//        t++;
//    }
//    int l = t;
//    for (auto i : cur->letters) {
////        cout << i.first;
//        dfs(i.second, n + 1);
//        if (t > b) b = t;
//        t = l;
//    }
//}
//
//void Tree::print() {
//    dfs(this, 0);
//    cout << b;
//}

bool contain(string &a, string &b) {
    bool ans = true;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            ans = false;
            break;
        }
    }
    return ans;
}

int c[2000][2000];

int search(int cur, string *str) {
    priority_queue<int> p;
    p.push(0);
    string s = str[cur];
    for (int i = cur - 1; i >= 0; --i) {
        if (contain(str[i], s)) {
            if (c[i][cur] == -1) p.push(c[i][cur] = search(i, str));
            else p.push(c[i][cur]);
        }
    }
    return p.top() + 1;
}

bool compare(const string &a, const string &b) {
    return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;
//    string tmp;
    string a[n + 1];
    fill(c[0], c[0] + 2000*2000, -1);
//    Tree a;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
//        cin >> tmp;
//        a.add(tmp);
    }

    sort(a, a + n, compare);
    priority_queue<int> p;
    p.push(0);
    for (int i = n - 1; i >= 0; --i) p.push(search(i, a));
    cout << p.top() << endl;

//    a.print();
    return 0;
}
