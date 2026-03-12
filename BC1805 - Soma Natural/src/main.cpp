
#include <iostream>
using namespace std;

int main() {
    unsigned long long a, b, n, sum = 0;

	cin >> a >> b; // C++

	//for (long long i = x; x <= y; x++) {
	//    sum += i;
	//}


    n = (b - a + 1);
	sum =  n * (a + b) / 2;

	cout << sum << endl; // C++

	return 0;
}
