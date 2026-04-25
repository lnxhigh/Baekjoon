#include <iostream>
#define MAX 7

using namespace std;

int N, M;
int arr[MAX];

void print(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }
    for (int i = 0; i < N; i++) {
        arr[cnt] = i+1;
        print(cnt+1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    print(0);

    return 0;
}
