#include <bits/stdc++.h>
#define N_MAX 1000000
using namespace std;

int N, H;
int trees[N_MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    long long start = 0;
    long long end = *max_element(trees, trees + N);
    long long answer;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long value = 0LL;
        for (int i = 0; i < N; i++) {
            long long height = 1LL * trees[i];
            if (height > mid) value += (height - mid);
        }
        
        if (value >= H) {
            answer = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << answer << '\n';
    
    return 0;
}
