//
// Maratona Fase Zero 2023
// Tempo limite: 5 segs (O(N^2) ok?)

#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define MAX_VAL 1000000000

bool match(const vector<int> &g, multiset<int> set_e, int c) { // O(NlogN)
    for (int i : g) { // O(N...)
        auto iter = set_e.find(abs(c - i)); // O(logN)
        if (iter == set_e.end()) return false;
        set_e.erase(iter); // ~O(logN)
    }
    return true;
}

int main() {
    int n, g, e;

    cin >> n;

    vector<int>   vec_g(n);
    multiset<int> set_e;

    for (int i = 0; i < n; i++) { // O(N)
        cin >> g;
        vec_g[i] = g;
    }

    for (int i = 0; i < n; i++) { // O(NlogN)
        cin >> e;
        set_e.insert(e);
    }

    int min_g = *min_element(vec_g.begin(), vec_g.end());
    int max_g = *max_element(vec_g.begin(), vec_g.end());
    int max_e = *max_element(set_e.begin(), set_e.end()); // O(1)? O(logN)? O(N)?

    int c1 = min (min_g + max_e, max_g - max_e);
    int c2 = max (min_g + max_e, max_g - max_e);

//    cout << "c1 = " << c1 << endl;
//    cout << "c2 = " << c2 << endl;

    if ((c1 > 0) && (c1 < MAX_VAL) && match(vec_g, set_e, c1)) { // O(NlogN)
        cout << c1 << endl;
    }

    if ((c2 > 0) && (c2 < MAX_VAL) && (c1 != c2) && match(vec_g, set_e,c2)) { // O(NlogN)
        cout << c2 << endl;
    }

    return 0;
}
