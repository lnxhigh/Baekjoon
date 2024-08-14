#include <bits/stdc++.h>
using namespace std;

int TC;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;

    while (TC--) {
        int N;
        multiset<int> s;

        cin >> N;
        for (int i = 0; i < N; i++) {
            char op; int x;
            cin >> op >> x;

            if (op == 'I') {
                s.insert(x);
            }
            else if (op == 'D') {
                if (s.empty()) continue;
                auto iter = (x == -1) ? s.begin() : --s.end();
                s.erase(iter);
            }
        }

        if (s.empty()) cout << "EMPTY" << '\n';
        else cout << *(--s.end()) << ' ' << *(s.begin()) << '\n';
    }

    return 0;
}
