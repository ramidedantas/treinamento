#include <iostream>
#include <string>

using namespace std;

string merge(const string& str1, const string& str2) {
    string res = str1 + str2;
    int idx1 = 0, idx2 = 0;

    for (int i = 0; i < res.size(); ) {
        if (idx1 < str1.size()) res[i++] = str1[idx1++];
        if (idx2 < str2.size()) res[i++] = str2[idx2++];
    }

    return res;
}

int main() {
    int n;

    cin >> n;

    while (n--) {
        string str1, str2;
        cin >> str1 >> str2;

        string res = merge(str1, str2);

        cout << res << endl;
    }

    return 0;
}
