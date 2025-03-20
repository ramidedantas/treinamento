//============================================================================
// Name        : BC3342.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int n, w, b;

	cin >> n;

	//n impar: W = ceil((n^2)/2); B = n^2 - W
	//n par: W = B = (n^2)/2

	int n2 = n * n;

	w = ceil((float)n2/2);

	b = n2 - w;

	cout << w << " casas brancas e " << b << " casas pretas" << endl;

	return 0;
}
