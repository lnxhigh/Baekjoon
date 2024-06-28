#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    N = (1 << N) + 1;
    printf("%d", N * N);
}
