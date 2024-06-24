#include <bits/stdc++.h>
using namespace std;

int N, B;
vector<char> letters;

char encode(int k) {
    if (k >= 10) { return 'A' + k - 10; }
    return '0' + k;
}

int main() {
    cin >> N >> B;

    while (N) {
        letters.push_back(encode(N % B));
        N /= B;
    }

    reverse(letters.begin(), letters.end());
    for (char letter : letters) cout << letter;
    cout << '\n';
    return 0;
}
