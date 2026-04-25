#include <stdio.h>

int main(void) {
	int arr[10] = { 0, };
	int i, j, temp;
	int digit = 0;
	int N;

	scanf("%d", &N);

	for (i = 0; N != 0; i++) {
		arr[i] = N % 10;
		N /= 10;
		digit++;
	}

	for (i = 9; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < digit; i++) {
		printf("%d", arr[i]);
	}

}