#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 10000

using namespace std;

int inverse(int x) {
    string str = to_string(x);
    std::reverse(str.begin(), str.end());
    return stoi(str);
}

// Busca com BFS
int steps_bfs(int a, int b) {
    bool visited[MAX + 1] = {};
    queue<pair<int, int>> q;
    q.emplace(a, 0);

    while (!q.empty()) {
        int x = q.front().first;
        int s = q.front().second;
        q.pop();

        visited[x] = true;

        if (x == b) return s;

        if ((x + 1 <= MAX) && !visited[x + 1])
            q.emplace(x + 1, s + 1);

        int _x = inverse(x);

        if ((_x <= MAX) && !visited[_x])
            q.emplace(_x, s + 1);
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << steps_bfs(a, b) << endl;
    }

    return 0;
}
