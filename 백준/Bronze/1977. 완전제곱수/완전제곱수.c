#include <stdio.h>
#include <math.h>

int main(void) {
	int i;
	int M, N;
	int low, high;
	int sum = 0, min;

	scanf("%d %d", &M, &N);

	low = ceil(sqrt(M));
	high = floor(sqrt(N));

	if (low > high) {
		printf("%d", -1);
		return 0;
	}
		
	else {
		for (i = low; i <= high; i++) {
			sum += i*i;
		}
		min = low*low;

		printf("%d\n", sum);
		printf("%d\n", min);

		return 0;
	}
}