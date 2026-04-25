#include <stdio.h>
#define MAX 100

int run(char* arr) {
	char first;
	int i;
	int cnt = 0;

	first = arr[0];
	for (i = 0; i < 100; i++) {
		if (arr[i] != first) {
			cnt++;
			first = arr[i];
		}
	}

	return cnt;

}

int kind(char* arr) {
	int list[26] = { 0 };
	int i;
	int cnt = 0;

	for (i = 0; arr[i] != 0; i++) {
		list[arr[i] - 97] = 1;
	}

	for (i = 0; i < 26; i++) {
		cnt += list[i];
	}
	
	return cnt;
}

int group(char* arr) {
	if (run(arr) == kind(arr))
		return 1;
	else
		return 0;
}

int main(void) {
	char arr[MAX][101] = { 0 };
	int N;
	int i;
	int cnt = 0;
	
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (i = 0; i < N; i++) {
		cnt += group(arr[i]);
	}
	
	printf("%d", cnt);
	
}