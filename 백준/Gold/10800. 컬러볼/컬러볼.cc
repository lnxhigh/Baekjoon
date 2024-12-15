#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;

int N;
pair<pair<int,int>,int> Balls[MAX];

int C[MAX], S[MAX];
map<pair<int,int>,int> SNC;
int X[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int color, size; 
        cin >> color >> size;
        pair<int,int> p = { size, color };
        Balls[i] = { p, i };
    }
    sort(Balls, Balls + N);

    int all = 0;
    for (int i = 0; i < N; i++) {
        auto [p, idx] = Balls[i];
        auto [size, color] = p;

        X[idx] = all - (S[size] + C[color] - SNC[p]);

        all += size;
        S[size] += size;
        C[color] += size;
        SNC[p] += size;
    }

    for (int i = 0; i < N; i++) {
        cout << X[i] << '\n';
    }

    return 0;
}
