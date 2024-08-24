#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int TC;

int main() {
    FastIO;
    cin >> TC;
    while (TC--) {
        long long N;
        cin >> N;
        bool X = (N % 10 == 0); // ...
        cout << X << '\n';
    }
    return 0;
}
