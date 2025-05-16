#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
int arr[100];
int b[100];

bool check(int i) {
    for (int x = b[i] - arr[i]; x <= b[i] + arr[i]; x++) {
        bool chk = true;

        for (int k = 0; k < n && chk; k++) {
            if (k == i) continue;
            else if (b[k] + arr[k] < x || b[k] - arr[k] > x) continue;
            if (arr[i] < arr[k]) chk = false;
        }

        if (chk) return true;
    }

    return false;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] *= 2;
    }

    int x = 0, m = arr[0];

    for (int i = 0; i < n; i++) {
        int lo = max(x + 1, arr[i]), hi = max(m, arr[i]);
        int nxt = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            bool chk = true;

            for (int k = 0; k < i && chk; k++) {
                if (mid - b[k] < min(arr[i] * 2, arr[k] * 2)) {
                    chk = false;
                }
            }

            if (chk) nxt = mid, hi = mid - 1;
            else lo = mid + 1;

            x = nxt;
            m = max(m, nxt + arr[i] * 2);
            b[i] = nxt;
        }
    }

    for (int i = 0; i < n; i++) {
        if (check(i)) cout << i + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
