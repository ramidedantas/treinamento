
#include <stdio.h>

int main() {

	int t;

	while (scanf("%d", &t) != EOF) {
		float min = 9999;
		float v;

		for (int i = 0; i < t; i++) {
			scanf("%f", &v);

			if (v < min) {
				min = v;
			}
		}

		printf("%.2f\n", min);
	}

	return 0;
}
