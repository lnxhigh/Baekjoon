#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using Rect = tuple<int,int,int,int>;
const int OFFSET = 10000;

int n, k;
vector<Rect> rect;
vector<pair<int,int>> result;
vector<int> answer;

int main() {
    FastIO

    cin >> n >> k;
    rect.resize(n);
    for (auto& [x1, y1, x2, y2] : rect) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += OFFSET, y1 += OFFSET, x2 += OFFSET, y2 += OFFSET;
    }

    for (int i = 0; i < n; i++) {
        const auto& [x1, y1, x2, y2] = rect[i];
        int area = (x2 - x1) * (y2 - y1);
        int rest = 0;

        for (int t = x1; t < x2; t++) {
            // [t, t + 1)
            vector<pair<int,int>> vec;

            for (int j = i + 1; j < n; j++) {
                const auto& [a1, b1, a2, b2] = rect[j];
                if (a1 > t || a2 <= t || b1 >= y2 || b2 <= y1) continue;
                vec.emplace_back(max(b1, y1), min(b2, y2));
            }

            if (vec.empty()) continue;
            sort(vec.begin(), vec.end());

            // line sweeping
            int sum = 0;
            int first = -1, last = -1;

            for (auto [a, b] : vec) {
                if (a > last) sum += (last - first), first = a, last = b;
                else last = max(last, b);
            }
            sum += last - first;

            // update
            rest += sum;
        }

        area -= rest;
        result.emplace_back(-area, i);
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < k; i++) {
        auto [area, idx] = result[i];
        answer.emplace_back(idx + 1);
    }
    
    sort(answer.begin(), answer.end());
    for (int idx : answer) cout << idx << ' ';
    cout << '\n';

    return 0;
}
