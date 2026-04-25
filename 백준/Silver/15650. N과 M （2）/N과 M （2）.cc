#include <iostream>
#define MAX 8
using namespace std;

int N, M;
int arr[MAX] = {0,};

bool promising(int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (arr[cnt] <= arr[i]) {
            return false;
        }
    }
    return true;
}

void print(int cnt) {
    if (cnt == M) {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        arr[cnt] = i+1;
        if (promising(cnt)) {
            print(cnt+1);
        }
    }
}

int main(void) {
    cin >> N >> M;
    print(0);
}
