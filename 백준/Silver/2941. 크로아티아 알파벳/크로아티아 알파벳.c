#include <stdio.h>

int main(void) {
	char arr[100+1];
	int i = 0;
	int cnt = 0;

	scanf("%s", arr);

	while (arr[i] != 0) {
		

		if (arr[i] == 'c') {
			if (arr[i + 1] == '=' || arr[i + 1] == '-') {
				cnt += 1;
				i += 2;
				continue;
			}
			else {
				cnt += 1;
				i += 1;
				continue;
			}	
		}

		else if (arr[i] == 'd') {
			if (arr[i + 1] == '-') {
				cnt += 1;
				i += 2;
				continue;
			}
			else if (arr[i + 1] == 'z') {
				if (arr[i + 2] == '=') {
					cnt += 1;
					i += 3;
					continue;
				}
				else {
					cnt += 2;
					i += 2;
					continue;
				}
			}
			else {
				cnt += 1;
				i += 1;
				continue;
			}
		}

		else if (arr[i] == 'l' || arr[i] == 'n') {
			if (arr[i + 1] == 'j') {
				cnt += 1;
				i += 2;
				continue;
			}
			else {
				cnt += 1;
				i += 1;
				continue;
			}
		}

		else if (arr[i] == 's' || arr[i] == 'z') {
			if (arr[i + 1] == '=') {
				cnt += 1;
				i += 2;
				continue;
			}
			else {
				cnt += 1;
				i += 1;
				continue;
			}
		}

		else {
			cnt += 1;
			i += 1;
			continue;
		}

	}

	printf("%d", cnt);

}