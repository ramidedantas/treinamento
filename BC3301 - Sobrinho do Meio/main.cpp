#include <iostream>

using namespace std;

int main() {
    int h, z, l;

    cin >> h >> z >> l;
    // cout << h << " " << z << " " << l;
    // return 0;

    int pri = max(h, max(z, l));
    int ter = min(h, min(z, l));
    int seg = (h + z + l) - pri - ter;

    string nomes[pri + 1];
    nomes[h] = "huguinho";
    nomes[z] = "zezinho";
    nomes[l] = "luisinho";

    cout << nomes[seg] << endl;

    return 0;
}