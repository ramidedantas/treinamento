#include <iostream>

using namespace std;

int main() {
    int d;

    cin >> d;

    // Marcos
//    while (d > 8) {
//        d -=8 ;
//    }
//
//    if (d == 8) {
//        printf("3\n");
//    } else if (d==7) {
//        printf("2\n");
//    } else {
//        printf("1\n");
//    }

//    d -= 5;
//    int s = (d % 8);

    cout << (d - 5) % 8 << endl;

    return 0;
}
