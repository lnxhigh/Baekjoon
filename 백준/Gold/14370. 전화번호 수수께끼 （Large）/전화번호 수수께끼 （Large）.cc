#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int TC;
string names[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
char identifier[10] = { 'Z', 'O', 'W', 'H', 'U', 'F', 'X', 'V', 'G', 'I' };
int order[10] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };

string solve(string cipher) {
    int alphabets[26], counts[10];
    memset(alphabets, 0, sizeof(alphabets));
    memset(counts, 0, sizeof(counts));

    for (char c : cipher) {
        alphabets[(int) (c - 'A')]++;
    }

    for (int k : order) {
        int cnt = alphabets[(int) (identifier[k] - 'A')];
        counts[k] += cnt;
        for (char c : names[k]) {
            alphabets[(int) (c - 'A')] -= cnt;
        }
    }

    string res = "";
    for (int i = 0; i < 10; i++) {
        res += string(counts[i], i + '0');
    }
    
    return res;
}

int main() {
    FastIO
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        string cipher;
        cin >> cipher;
        cout << "Case #" << tc << ": " << solve(cipher) << '\n';
    }
    return 0;
}
