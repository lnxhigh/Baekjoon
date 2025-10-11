#include <bits/stdc++.h>
using namespace std;

int n;
string arr[64];
int par[64];

int find(int x)
{
    if (x == par[x])
        return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y)
{
    x = find(x), y = find(y);

    if (x == y)
        return false;
    else if (x < y)
        swap(x, y);

    par[x] = y;
    return true;
}

int score(char x) {
    if (x >= 'a' && x <= 'z') {
        return x - 'a' + 1;
    }
    else if (x >= 'A' && x <= 'Z') {
        return x - 'A' + 1 + 26;
    }

    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // MST

    iota(par, par + n, 0);

    int total = 0;
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '0')
                continue;

            int w = score(arr[i][j]);
            total += w;

            edges.emplace_back(w, i, j);
        }
    }

    int sum = 0;
    int cnt = n;
    sort(edges.begin(), edges.end());

    for (auto [w, u, v] : edges)
    {
        if (!merge(u, v))
            continue;

        cnt--;
        sum += w;
    }

    int ans = (cnt == 1) ? (total - sum) : -1;
    cout << ans << '\n';

    return 0;
}
