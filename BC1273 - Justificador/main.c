
#include <stdio.h>
#include <string.h>

int main() {
	int n;

	scanf("%d", &n);

	while (n) {
		char w[n][51];

		int max = -1, len;

		for (int i = 0; i < n; i++) {
			scanf("%s", w[i]);
			len = strlen(w[i]);
			if (len > max) max = len;
		}

		for (int i = 0; i < n; i++) {
			printf("%*s\n", max, w[i]);
		}

		scanf("%d", &n);

		// só botar linha branco se houver um próximo teste
		// do contrário: presentation error
		if (n) printf("\n");
	}

	return 0;
}
