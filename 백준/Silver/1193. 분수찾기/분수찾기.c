#include <stdio.h>
#include <math.h>

int main(void) {
	int x, n;
	double f;

	scanf("%d", &x);
	f = sqrt(2 * x + 0.25) - 0.5;
	n = ceil(f);

	if (n % 2 == 1) {
		printf("%d/%d", 1 - x + n * (n + 1) / 2, x - n * (n - 1) / 2);
	}
	else {
		printf("%d/%d", x - n * (n - 1) / 2, 1 - x + n * (n + 1) / 2);
	}
}