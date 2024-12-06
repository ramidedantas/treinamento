#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {

    int n;
    double angle;

    cin >> angle >> n;

    set<pair<double, double>> shadows;

    for (int i = 0; i < n; i++) {
        double x, h, s;

        cin >> x >> h;

//        s = h / tan(angle * 3.14159265359/180.0);
        s = h / tan(angle * M_PI/180.0);

        shadows.emplace(x, s);
    }

    double shadow_total = 0;
    double shadow_ini = -1, shadow_end = -1;

    for (auto p : shadows) {
        double x = p.first;
        double s = p.second;

        if (x > shadow_end) {
            shadow_total += shadow_end - shadow_ini;
            shadow_ini = x;
            shadow_end = x + s;
        } else if (x + s > shadow_end) {
            shadow_end = x + s;
        }
    }

    shadow_total += shadow_end - shadow_ini;

//    cout << shadow_total << endl;

    printf("%.5f\n", shadow_total);

    return 0;
}
