#include <stdio.h>

int sugar(int N) {
	int i = 0;

	while (1) {
		if (N - 3 * i < 0)
			return -1;
		if ((N - 3 * i) % 5 == 0)
			return (i + (N - 3 * i) / 5);
		i++;
	}
}

int main(void) {
	int N;

	scanf("%d", &N);
	printf("%d", sugar(N));
}
