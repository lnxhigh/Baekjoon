#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;

int f(int x)
{
    return x ^ (x >> 1); // gray code
}

int main()
{
    FastIO;
    cin >> n;

    int cnt = (1 << n) - 1;
    cout << cnt << '\n';

    for (int i = 0; i < cnt; i++)
    {
        int x = f(i);
        int nxt = f(i + 1);

        int t = 0;
        while ((1 << t) < (x ^ nxt))
            t++;
        cout << ++t << '\n';
    }
    cout << n << '\n';

    return 0;
}
