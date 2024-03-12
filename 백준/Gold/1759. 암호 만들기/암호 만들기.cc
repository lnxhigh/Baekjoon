#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
char alphabets[20];
vector<int> bits;
vector<string> passwords;

bool is_vowel(char c) {
    for (char vowel : {'a', 'e', 'i', 'o', 'u'}) {
        if (c == vowel) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> alphabets[i];
    }
    sort(alphabets, alphabets + C);

    for (int bit = 0; bit < (1 << C); bit++) {
        int cnt = 0;
        for (int i = 0; i < C; i++) {
            if (bit & (1 << i)) cnt++;
        }
        if (cnt == L) bits.push_back(bit);
    }

    for (int bit : bits) {
        int cnt = 0;
        int v = 0, c = 0;
        char password[20];
        password[L] = '\0';

        for (int i = 0; i < C; i++) {
            if (bit & (1 << i)) {
                password[cnt++] = alphabets[i];
                if (is_vowel(alphabets[i])) v++;
                else c++;
            }
        }

        if (v >= 1 and c >= 2) {
            passwords.push_back(string(password));
        }
    }
    
    sort(passwords.begin(), passwords.end());
    for (string password : passwords) {
        cout << password << '\n';
    }

    return 0;
}