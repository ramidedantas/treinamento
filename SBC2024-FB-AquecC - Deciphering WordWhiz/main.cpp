#include <iostream>
#include <vector>
#include <map>

using namespace std;

string pattern(const string &secret, const string &guess) {
    string res = "XXXXX";

    for (int i = 0; i < guess.size(); i++) {
        if (guess[i] == secret[i])
            res[i] = '*';
        else if (secret.find(guess[i]) != string::npos)
            res[i] = '!';
    }

    return res;
}

int main() {

    int n;

    cin >> n;

    vector<string> words (n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    map<string, int> patterns;

    string &secret = words[0];

    for (string &w : words) {
        string pat = pattern(secret, w);
        patterns[pat]++;
//        cout << pat << endl;
    }

    int g;

    cin >> g;

    for (int i = 0; i < g; i++) {
        string guess;
        cin >> guess;
        cout << patterns[guess] << endl;
    }

    return 0;
}
