#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;

    while (getline(cin, str)) {
        vector<int> letras(26, 0);

        for (auto c : str) {
            if (c >= 'a' && c <= 'z')
                letras[c - 'a']++;
        }

        bool comma = false;
        for (int i = 0; i < 26; i++) {
            while (letras[i] == 0) i++;
            char inicio = (char)(i + 'a');
            while (letras[i] != 0 && i < 26) i++;
            char final = (char)(--i + 'a');
            if (inicio - 'a' < 26 && final - 'a' < 26) {
                if (comma) cout << ", ";
                cout << inicio << ":" << final;
                comma = true;
            }
        }
        cout << endl;
    }

    return 0;
}
