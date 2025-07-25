#include <iostream>
#include <queue>

using namespace std;

int main() {

    int d, c, r, t;

    cin >> d >> c >> r;

    queue<int> C, R;

    while (c--) { cin >> t; C.push(t); }
    while (r--) { cin >> t; R.push(t); }

    int res = 0;
    while (true) {
        if (!C.empty() && d >= C.front()) {
            d -= C.front();  C.pop();
            res++;
        } else if (!R.empty()) {
            d += R.front(); R.pop();
            res++;
        } else break;
    }

    cout << res << endl;

    return 0;
}
