#include <stdio.h>

int main(void) {
	int N, n;
	int cnt = 0;

	scanf("%d", &N);

	n = N;
	do {
		cnt++;
		if (n < 10) {
			n = 10 * n + n;
		}
		else {
			n = 10 * (n % 10) + ((n / 10 + n % 10) % 10);
		}
	} while (N != n);

	printf("%d", cnt);

}