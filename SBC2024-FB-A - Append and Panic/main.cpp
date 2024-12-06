#include <iostream>
#include <set>

using namespace std;

int main() {

    string str;

    cin >> str;

    set<char> letters;

    for (auto c : str) {
        letters.insert(c);
    }

    cout << str.size() - letters.size() << endl;

    return 0;
}
