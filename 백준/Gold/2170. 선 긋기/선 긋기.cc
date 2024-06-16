#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
const int N_MAX = 1000000;
pair<int,int> line[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    int s, e;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        line[i] = { s, e };
    }

    sort(line, line + N);

    int res = line[0].Y - line[0].X;
    int last = line[0].Y;
    
    for (int i = 1; i < N; i++) {
        if (line[i].Y <= last) continue;
        res += line[i].Y - max(line[i].X, last);
        last = line[i].Y;
    }

    cout << res << '\n';
    return 0;
}
