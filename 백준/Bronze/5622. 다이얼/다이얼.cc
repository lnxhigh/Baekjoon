#include <bits/stdc++.h>
using namespace std;

string word;
unordered_map<char,int> dial;
int answer = 0;

int f(char letter) {
    if (letter < 'A' || letter > 'Z') return 1;
    
    if      (letter <= 'O') return (letter - 'A') / 3 + 2;
    else if (letter <= 'S') return 7;
    else if (letter <= 'V') return 8;
    else if (letter <= 'Z') return 9;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> word;

    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        dial[letter] = f(letter);
    }
    for (char letter : word) {
        answer += (dial[letter] + 1);
    }

    cout << answer << '\n';

    return 0;
}
