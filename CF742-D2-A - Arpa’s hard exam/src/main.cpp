#include <iostream>
using namespace std;

int main() {

	int n, v = 1;

	cin >> n;

	n = ((n - 1) % 4) + 1;

	while (n-- > 0) {
		v = (v * 8) % 10;
	}

	cout << v << endl;

	return 0;
}
