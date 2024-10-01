#include <iostream>
using namespace std;
const int MOD = 10007;

int n, twos, tmp, cnt = 0;

int power(int x, int p) 
{
    int ans = 1;
    while (p) 
    {
        if (p & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        p >>= 1;
    }

    return ans;
}

int combi(int n, int k) 
{
    int ans = 1, mul = 1;
    k = min(k, n - k);

    for (int i = 0; i < k; i++) 
    {
        ans = ans * (n - i) % MOD;
        mul = mul * (i + 1) % MOD;
    }

    int inv = power(mul, MOD - 2);
    return ans * inv % MOD;
}

int main(void)
{
	cin >> n;
	twos = n / 2;

	for (int i = 0; i <= twos; i++)
	{
		tmp = combi(n-i, i) * power(2, i) % MOD;
		cnt += tmp;
	}
    cout << cnt % MOD << '\n';
	return 0;
}
