#include <bits/stdc++.h>
#define ll long long
#define N_MAX 200000
using namespace std;

int N, C;
int house[N_MAX];
int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> house[i];
    sort(house, house + N);

    int start = 0, end = house[N-1] - house[0];
    while (start <= end) {
        int mid = (start + end) / 2;
        int value = 1;
        int k = 0;
        for (int i = 1; i < N; i++) {
            if (house[i] - house[k] >= mid) {
                value++; k = i;
            }
        }
        if (value >= C) {
            start = mid + 1;
            answer = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
