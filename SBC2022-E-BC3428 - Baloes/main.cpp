#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;

    // input
    cin >> n;
    vector<int> B(n);
    auto Bi = B.begin();
    while (Bi != B.end()) { cin >> *Bi++; }

    // O(NlogN)
    map<int, int> arrows;
    int count = 0;
    for (int b : B) { // O(N)
        if (arrows[b + 1] > 0) {
            arrows[b + 1]--; // O(logN)
        }  else {
            count++;
        }
        arrows[b]++;
    }

    cout << count << endl;

    return 0;
}
