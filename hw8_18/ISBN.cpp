// vijos的训练计划 章节2 1484

#include <iostream>
#include <string>

using namespace std;

int main() {
    char c;
    string s;
    int sum = 0;
    int i = 1;
    while (cin >> c) {
        s.push_back(c);
        if (c != '-' && i < 10) sum += ((c - '0') * i++);
    }

    int id = sum % 11 + '0';
    int id2 = (id > '9' ? 'X' : id);
    bool b = (id2 == *s.rbegin());

    if (b) cout << "Right";
    else {
        *s.rbegin() = id2;
        cout << s;
    }
    return 0;
}
