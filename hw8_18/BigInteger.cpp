// vijos 1375

#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

struct BigInteger {
private:
    vector<int> num;

public:
    explicit BigInteger(vector<int> &str) : num(str) {}

    explicit BigInteger(const string &str) {
        setNum(str);
    }

    void setNum(const string &str) {
        num.clear();
        for (char i : str) num.push_back(i - '0');
    }

private:
    static void carry(vector<int> &res) {
        for (auto i = res.rbegin(); i != res.rend(); ++i) if (*i > 9) {
            int p = *i / 10;
            int q = *i % 10;
            *i = q;
            if (i + 1 == res.rend()) {
                res.insert(res.begin(), p);
                break;
            } else *(i + 1) += p;
        }
    }

    static int compare(vector<int> &x, vector<int> &y) {
        int dif = (int)(x.size() - y.size());
        if (dif < 0) {
            swap(x, y);
            dif = -dif;
        }
        return dif;
    }

public:
    BigInteger operator+(const BigInteger &x) const {
        vector<int> big = num, small = x.num;
        int dif = compare(big, small);
        vector<int> res;
        res.reserve(80);
        for (int i = 0; i < dif; ++i) res.push_back(big[i]);
        for (int i = dif; i < big.size(); ++i) res.push_back(big[i] + small[i - dif]);
        carry(res);
        return BigInteger(res);
    }

    BigInteger operator+=(const BigInteger &x) {
        return *this = *this + x;
    }

    void print() {
        for (int i : num) cout << i;
        cout << endl;
    }

    BigInteger operator*(const BigInteger &x) const {
        vector<int> big = num, small = x.num;
        compare(big, small);
        array<vector<int>, 10> lib;
        lib[1] = small;
        for (int i = 2; i < 10; ++i) {
            for (int j : small) lib[i].push_back(j * i);
            carry(lib[i]);
        }

        int tot = (int)(big.size() + small.size());
        int res[tot];
        fill(res, res + tot, 0);

        int begin = tot - 1;
        for (int i = (int)big.size() - 1; i >= 0; --i, --begin) {
            vector<int> tmp = lib[big[i]];
            for (int j = (int)tmp.size() - 1, k = begin; j >= 0; --j, --k) res[k] += tmp[j];
        }

        begin = 0;
        for (int i = 0; i < tot; ++i) {
            if (res[i] == 0) begin++;
            else break;
        }

        vector<int> pro;
        for (int i = begin; i < tot; ++i) pro.push_back(res[i]);
        carry(pro);
        if (pro.empty()) pro.push_back(0);
        return BigInteger(pro);
    }

    bool operator<=(const BigInteger &x) const {
        bool ans = false;
        if (x.num.size() > num.size()) ans = true;
        else if (x.num.size() == num.size()) {
            ans = true;
            for (int i = 0; i < num.size(); ++i)
                if (x.num[i] > num[i]) break;
                else if (x.num[i] < num[i]) {
                    ans = false;
                    break;
                }
        }
        return ans;
    }

    BigInteger mid() const {
        vector<int> res;
        int rest = 0;
        for (int i : num) {
            rest += i;
            res.push_back(rest / 2);
            rest = (rest & 1) * 10;
        }
        if (*(res.begin()) == 0) res.erase(res.begin());
        return BigInteger(res);
    }

    bool operator==(BigInteger &x) const {
        bool ans = true;
        if (x.num.size() != num.size()) ans = false;
        else for (int i = 0; i < num.size(); ++i)
            if (x.num[i] != num[i]) {
                ans = false;
                break;
            }
        return ans;
    }

    bool operator!=(BigInteger &x) const {
        return !(*this == x);
    }
};

BigInteger f(BigInteger &x) {
    return x * (x * x + x + BigInteger("3"));
}

int main() {
    string str;
    cin >> str;
    BigInteger target = BigInteger(str);

    BigInteger right = target;
    BigInteger left = BigInteger("0");

    while (left + BigInteger("1") != right) {
        BigInteger mid = (right + left).mid();
        BigInteger p = f(mid);
//        cout << "left ";
//        left.print();
//        cout << "mid ";
//        mid.print();
//        cout << "right ";
//        right.print();
//        cout << "f(p) ";
//        p.print();
//        cout << endl;

        if (p <= target) left = mid;
        else right = mid;
    }
    if (f(right) <= target) {
        right.print();
//        right += BigInteger("1");
//        f(right).print();
    }
    else {
        left.print();
//        left += BigInteger("1");
//        f(left).print();
    }
    return 0;
}