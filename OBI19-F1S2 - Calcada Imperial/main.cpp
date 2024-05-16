#include <iostream>

#include <list>
#include <algorithm>

using namespace std;

struct value_t {
    int num = -1;
    list<int> pos;
};

bool operator < (const value_t &a, const value_t&b) {
    return (a.pos.size() > b.pos.size());
}

int max_seq(value_t v1, value_t v2) {
    list<pair<int, int>> seq;

    while (!v1.pos.empty() && !v2.pos.empty()) {
        int p1 = v1.pos.front();
        int p2 = v2.pos.front();

        if (p1 < p2) {
            if (seq.empty() || seq.back().first != v1.num)
                seq.emplace_back(v1.num, p1);
            v1.pos.pop_front();
        } else {
            if (seq.empty() || seq.back().first != v2.num)
                seq.emplace_back(v2.num, p2);
            v2.pos.pop_front();
        }
    }

    if (!v1.pos.empty() && v2.pos.empty()) {
        int p1 = v1.pos.front();
        if (seq.empty() || seq.back().first != v1.num)
            seq.emplace_back(v1.num, p1);
    }

    if (v1.pos.empty() && !v2.pos.empty()) {
        int p2 = v2.pos.front();
        if (seq.empty() || seq.back().first != v2.num)
            seq.emplace_back(v2.num, p2);
    }

//    cout << "seq: ";
//    for (auto & i : seq) {
//        cout << i.first << " ";
//    }
//    cout << endl;

    return (int)seq.size();
}

int main() {

    int n;

    cin >> n;

    int v[n];
    value_t values[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        values[v[i]].num = v[i];
        values[v[i]].pos.push_back(i);
    }

    sort(&values[0], &values[n + 1]);

//    for (int i = 0; i < n; i++) {
//        cout << "num = " << values[i].num << " pos.size() = " << values[i].pos.size() << endl;
//    }

    int k = 0;
    while (values[k].num != -1) k++;

    int best = -1;

    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            auto s1 = (int)values[i].pos.size();
            auto s2 = (int)values[j].pos.size();
            if ((s1 + s2) < best)
                break;
            best = max(best, max_seq(values[i], values[j]));
        }
    }

    cout << best << endl;

    return 0;
}
