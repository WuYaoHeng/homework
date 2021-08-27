// vijos 1790

#include <iostream>
#include <queue>
#include <list>
using namespace std;

struct Graph {
    list<int> *data;
    int *in;
    int len;

    explicit Graph(int num) {
        this->len = num;
        data = new list<int>[len];
        in = new int[len];
        fill(in, in + len, 0);
    }

    ~Graph() {
        delete[] data;
        delete[] in;
    }

    void insert(int x, int y) const {
        data[y - 1].push_back(x - 1); // y -> x
    }

    void count() const {
        for (list<int> *i = data; i != data + len; ++i) {
            i->sort();
            i->unique();
            i->reverse();
            for (int j : *i) in[j]++;
        }
    }
};

void topSort(Graph& g) {
    g.count();

    int len = g.len;
    int topNum[len];
    int cot = len;

    priority_queue<int> arr;
    for (int i = len - 1; i >= 0; i--) if (g.in[i] == 0) {
        arr.push(i);
//        cout << i << " ";
    }
//    cout << endl << endl << endl;

    int tmp;
    while (!arr.empty()) {
        tmp = arr.top();
        arr.pop();
//        cout << "cur: " << tmp << endl << endl;

        topNum[tmp] = cot--;

        list<int> cur = g.data[tmp];
        if (!cur.empty()) {
            for (int i : cur) if (--g.in[i] == 0) {
                arr.push(i);
//                cout << i << " ";
            }
//            cout << endl;
        }
    }

    for (int i = 0; i < len; ++i) cout << topNum[i] << " ";
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph g = Graph(n);
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g.insert(x, y);
    }

    topSort(g);

    return 0;
}
