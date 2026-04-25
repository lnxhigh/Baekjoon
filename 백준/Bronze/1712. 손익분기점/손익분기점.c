#include <stdio.h>
#include <math.h>

int main(void) {
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	if (B >= C)
		printf("%d", -1);

	else {
		printf("%d", A / (C - B) + 1);
	}
}