#include <bits/stdc++.h>
using namespace std;

string N;

string minus_(string from) {
    int len = from.size();
    for (int i = len - 1; i >= 0; --i) {
        if (from[i] > '0') { from[i]--; break; } 
        else { from[i] = '9'; }
    }

    if (from[0] == '0' && len > 1) { from.erase(0, 1); }
    return from;
}

string multiply_(string left, string right) {
    int L = left.size(), R = right.size();
    vector<int> res(L+R, 0);

    for (int i = L-1; i >= 0; i--) {
        for (int j = R-1; j >= 0; j--) {
            int prod = (left[i] - '0') * (right[j] - '0');

            int a = i + j;
            int b = i + j + 1;

            int sum = prod + res[b];
            res[a] += sum / 10;
            res[b] = sum % 10;

            int c = a;
            while (c >= 0 && res[c] >= 10) {
                res[c] -= 10;
                res[--c] += 1;
            }
        }
    }

    string val = "";
    bool startWithZero = true;
    for (int c : res) {
        if (c != 0) startWithZero = false;
        if (!startWithZero) val += (c + '0');
    }
    return val;
}

int main() {
    cin >> N;
    if (N != "1") { N = minus_(N); N = multiply_(N, "2"); }
    cout << N << '\n';
    return 0;
}
