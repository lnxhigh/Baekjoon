#include <stdio.h>
#include <math.h>

int digitsum(int n) {
	int x = 0;

	while (n != 0) {
		x += n % 10;
		n /= 10;
	}

	return x;
}

int d(int n) {
	return n + digitsum(n);
}

int main(void) {
	int arr[10035] = { 0 };
	int i;

	for (i = 1; i <= 10000; i++) {
		arr[d(i)-1] = 1;
	}

	for (i = 0; i <= 10000; i++) {
		if (!arr[i])
			printf("%d\n", i + 1);
	}

}