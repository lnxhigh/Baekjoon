#include <bits/stdc++.h>
using namespace std;

int A[100][100];
int x, y, k;
int R = 3, C = 3;

void input() {
    cin >> x >> y >> k;
    --x, --y;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
}

int arrange(int n, bool flag) {
    vector<pair<int,int>> v;
    unordered_map<int,int> mp;

    int K = flag ? C : R;
    for (int i = 0; i < K; i++) {
        int a = flag ? n : i;
        int b = flag ? i : n;

        if (A[a][b] == 0) continue;
        mp[A[a][b]]++;
        A[a][b] = 0;
    }

    for (auto p : mp) v.push_back(p);
    sort(v.begin(), v.end(), [] (const pair<int,int> &a, const pair<int,int> &b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    
    int L = min((int) v.size(), 50);

    for (int i = 0; i < L; i++) {
        if (flag) {
            A[n][2 * i]     = v[i].first;
            A[n][2 * i + 1] = v[i].second;
        }
        else {
            A[2 * i][n]     = v[i].first;
            A[2 * i + 1][n] = v[i].second;
        }
    }

    return L << 1;
}

int main() {
    input();

    int t = 0;
    while (t <= 100) {
        if (A[x][y] == k) break;
        t++;

        bool flag = R >= C;
        int K = flag ? R : C;
        
        int newLen = 0;
        for (int i = 0; i < K; i++) {
            int L = arrange(i, flag);
            newLen = max(newLen, L);
        }

        int& V = flag ? C : R;
        V = newLen;
    }

    if (t > 100) t = -1;
    cout << t << '\n';
    return 0;
}
