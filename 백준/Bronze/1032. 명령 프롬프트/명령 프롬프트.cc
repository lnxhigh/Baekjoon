#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 6;
string files[MAX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> files[i];
    }

    int L = files[0].size();

    for (int i = 0; i < L; i++) {
        bool same = true;
        char cur = files[0][i];

        for (int f = 0; f < N; f++) {
            if (files[f][i] != cur) {
                same = false;
                break;
            }
        }

        char letter = same ? cur : '?';
        cout << letter;
    }

    cout << '\n';
    return 0;
}
