#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

string a, b;

int main() {
    FastIO
    cin >> b >> a;

    deque<char> x, y;
    for (char c : a) x.push_back(c);
    for (char c : b) y.push_back(c);

    while (!x.empty() && !y.empty() && x.front() == y.front()) {
        x.pop_front();
        y.pop_front();
    }

    while (!x.empty() && !y.empty() && x.back() == y.back()) {
        x.pop_back();
        y.pop_back();
    }
    
    cout << x.size() << '\n';
    return 0;
}
