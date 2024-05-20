#include <bits/stdc++.h>
#define ll long long
#define N_MAX 20
using namespace std;

int N;
ll problem, k;
vector<int> arr;
ll factorial[N_MAX+1];

void swap(int i, int j, vector<int> &arr) {
    if (i == j) return;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print(ll k, vector<int> &arr) {
    for (int i = 0; i < N; i++) {
        sort(arr.begin() + i, arr.end());
        int x = k / factorial[N-i-1];
        swap(i, i + x, arr);
        k %= factorial[N-i-1];
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return;
}

ll rank_(vector<int> &arr) {
    ll res = 0LL;
    for (int i = 0; i < N; i++) {
        int value = 0;
        for (auto iter = arr.begin() + i; iter != arr.end(); ++iter) {
            if (arr[i] > *iter) value++;
        }
        res += factorial[N-i-1] * value;
    }

    return res;
}

int main() {
    cin >> N;
    cin >> problem;

    factorial[0] = 1;
    for (ll i = 1; i <= N_MAX; i++) {
        factorial[i] = factorial[i-1] * i;
    }

    if (problem == 1) {
        cin >> k;
        for (int i = 0; i < N; i++) {
            arr.push_back(i+1);
        }
        print(k-1, arr);
    }
    else if (problem == 2) {
        for (int i = 0; i < N; i++) {
            cin >> k;
            arr.push_back(k);
        }
        cout << rank_(arr) + 1LL << '\n';
    }

    return 0;
}
