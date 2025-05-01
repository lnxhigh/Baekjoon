#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;

int n;
int arr[MAX];

int two[100];
int four[10000];
int four_max[100];

int main() {
    FastIO
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        two[arr[i] % 100]++;
        four[arr[i] % 10000]++;
    }

    for (int i = 0; i < 100; i++) {
        int cnt = 0;
        for (int j = i; j < 10000; j += 100) {
            cnt = max(cnt, four[j]);
        }
        four_max[i] = cnt;
    }

    vector<pair<int,int>> vec;
    for (int i = 0; i < 100; i++) {
        vec.push_back({ two[i], i });
    }
    sort(vec.rbegin(), vec.rend());

    int ans = 0;

    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (x == y) continue;

            int sum = 0;

            // First

            if (two[x]) {
                sum += 300000;
            }

            // Second

            sum += four_max[y] * 4000;

            // Third

            int num = 0;
            int cnt = 0;
            
            for (int i = 0; i < 100 && num < 3; i++) {
                auto [val, digits] = vec[i];
                if (digits == x || digits == y) continue;
                num++;
                cnt += val;
            }

            sum += cnt * 500;

            // Update answer

            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';

    return 0;
}
