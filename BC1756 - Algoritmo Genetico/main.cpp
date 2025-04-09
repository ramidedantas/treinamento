#include <iostream>
#include <iomanip>

using namespace std;

double prob(const string& ind1, const string &ind2, double p) {
    double res = 1;
    for (int i = 0; i < ind1.size(); i++) {
        if (ind1[i] != ind2[i]) res *= p;
        else res *= (1 - p);
    }
    return res;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        int n, y;
        double p;
        string ind1, ind2, indF;

        cin >> n >> y >> p;
        cin >> ind1 >> ind2 >> indF;

        string indX = ind1.substr(0, y) + ind2.substr(y);
        string indY = ind2.substr(0, y) + ind1.substr(y);

        double _resX_F = 1 - prob(indX, indF, p);
        double _resY_F = 1 - prob(indY, indF, p);

        cout << fixed << setprecision(7)  << (1 - (_resX_F * _resY_F)) << endl;
    }

    return 0;
}
