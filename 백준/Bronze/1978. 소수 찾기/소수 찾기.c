#include <stdio.h>
#include <math.h>

int prime(int n) {
	int i, x;
	int cnt = 0;

	if (n == 1)
		return 0;

	x = floor(sqrt(n * 1.0));

	for (i = 2; i <= x; i++) {
		if (n % i == 0)
			cnt++;
	}

	if (cnt > 0)
		return 0;
	else
		return 1;
}

int main(void) {
	int N, i;
	int arr[100];
	int ans = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < N; i++) {
		ans += prime(arr[i]);
	}

	printf("%d", ans);

	return 0;
}