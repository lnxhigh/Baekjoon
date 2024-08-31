#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
string prev_;
const int MAX = 1 << 17;
string animals[MAX];

string solve() {
    int alpha[26];
    memset(alpha, 0, sizeof(alpha));

    bool found = false;
    char last = prev_[(int) prev_.size() - 1];

    for (int i = 0; i < N; i++) {
        const string &animal = animals[i];
        char first = animal[0];
        alpha[(int) (first - 'a')]++;
    }

    string res;
    for (int i = 0; i < N; i++) {
        const string &animal = animals[i];
        if (animal[0] != last) continue;

        if (!found) { res = animal; found = true; }

        char next = animal[(int) animal.size() - 1];

        bool beat = alpha[(int) (next - 'a')] == 0;
        beat = beat || (animal[0] == next && alpha[(int) (next - 'a')] == 1);
        if (beat) return animal + "!";
    }

    if (found) return res;
    return "?";
}

int main() {
    FastIO
    cin >> prev_;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> animals[i];
    }
    cout << solve() << '\n';
    return 0;
}
