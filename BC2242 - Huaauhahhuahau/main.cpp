#include <iostream>
#include <cstring>

using namespace std;

#define VOGAL(x) ((x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u')

int palindromo(const char * str, int len) {
    for (int i = 0; i < (len/2); i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main() {
    char str[51];
    char vogais[51];

    cin >> str;

    int len = strlen(str);

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (VOGAL(str[i]))
            vogais[j++] = str[i];
    }
    vogais[j] = 0;

    cout << (palindromo(vogais, j)?"S":"N") << endl;

}
