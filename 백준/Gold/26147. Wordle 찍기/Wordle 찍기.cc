#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
vector<string> words;

string gen(const string& pat) {
    string original = "ABCDE";
    string result = "ABCDE";
    vector<int> yellow, gray;

    for (int i = 0; i < 5; i++) {
        if (pat[i] == 'Y') yellow.emplace_back(i);
        else if (pat[i] == 'B') gray.emplace_back(i);
    }

    if (yellow.size() == 1u) {
        int idx = yellow[0];
        result[idx] = original[gray[0]];
    }
    else if (yellow.size() > 1u) {
        int len = yellow.size();
        for (int i = 0; i < len; i++) {
            int cur = yellow[i];
            int nxt = yellow[(i + 1) % len];
            result[cur] = original[nxt];
        }
    }

    for (int idx : gray) {
        result[idx] += 5;
    }

    return result;
}

int main() {
    FastIO
    cin >> n;
    words.resize(n);
    for (string& word : words) cin >> word;

    bool chk = true;

    for (const string& word : words) {
        int g = 0, y = 0, b = 0;
        for (char c : word) (c == 'G') ? g++ : (c == 'Y') ? y++ : b++;
        if (g == 4 && y == 1 && b == 0) chk = false;
    }

    if (!chk) {
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        cout << "ABCDE" << "\n";
        for (const string &word : words) {
            cout << gen(word) << "\n";
        }
    }

    return 0;
}
