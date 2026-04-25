#include <stdio.h>
#define MAX 1000

int main(void) {
	int N;
	int i, j;
	int arr[MAX] = { 0 };
	int m, temp;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", arr+i);
	}
	

	for (i = 0; i < N; i++) {
		m = i;
		for (j = i; j < N; j++) {
			if (arr[j] < arr[m])
				m = j;
		}

		temp = arr[i];
		arr[i] = arr[m];
		arr[m] = temp;

	}

	for (i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

}
