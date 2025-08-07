#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    auto INI = {'N', 'L', 'S', 'O'};
    map<pair<char, char>, char> next_o;
    map<char, pair<int, int>> move_front;

    next_o[{'N', 'D'}] = 'L';
    next_o[{'N', 'E'}] = 'O';
    next_o[{'S', 'D'}] = 'O';
    next_o[{'S', 'E'}] = 'L';
    next_o[{'O', 'D'}] = 'N';
    next_o[{'O', 'E'}] = 'S';
    next_o[{'L', 'D'}] = 'S';
    next_o[{'L', 'E'}] = 'N';

    move_front['N'] = {0, -1};
    move_front['S'] = {0, +1};
    move_front['L'] = {+1, 0};
    move_front['O'] = {-1, 0};

    int n, m, s;

    cin >> n >> m >> s;

    while (n) {
        vector<string> M(n);
        string ops;

        int x, y;

        for (int i = 0; i < n; i++) {
            cin >> M[i];
            for (char c : INI) {
                int j;
                if ((j = M[i].find(c)) != string::npos) {
                    y = i;
                    x = (int) j;
                    break;
                }
            }
        }
        cin >> ops;

        int count = 0, nx, ny;
        char curr_o = M[y][x];

        for (auto op : ops) {
            switch (op) {
                case 'D':
                case 'E':
                        curr_o = next_o[{curr_o, op}];
                        break;
                case 'F': {
                    auto [dx, dy] = move_front[curr_o];
                    nx = max(0, min(x + dx, m - 1));
                    ny = max(0, min(y + dy, n - 1));
                    if (M[ny][nx] == '#') break;
                    x = nx; y = ny;
                    if (M[y][x] == '*') {
                        count++;
                        M[y][x] = '.';
                    }
                    break;
                }
                default:
                        exit(1);
            }
        }

        cout << count << endl;

        cin >> n >> m >> s;
    }

    return 0;
}
