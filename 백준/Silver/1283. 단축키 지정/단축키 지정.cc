#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 30;
string sentences[N_MAX];
int shortcuts[N_MAX];

bool alphabet[26];

int FindShortcut(string sentence) {
    
    // First consider the initial letters of all words in the description
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ' ') continue;
        if (i == 0 || sentence[i-1] == ' ') {
            char initial = tolower(sentence[i]);
            int k = initial - 'a';
            if (!alphabet[k]) {
                alphabet[k] = true;
                return i;
            }
        }
    }
    
    // If all initial letters are already assigned, then consider all remaining letters
    for (int i = 0; i < sentence.size(); i++) {
        char c = sentence[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            char remain = tolower(c);
            int k = remain - 'a';
            if (!alphabet[k]) {
                alphabet[k] = true;
                return i;
            }
        }
    }

    // If none of the letters in the description are available, 
    // then the option has no shortcut. 
    return -1;
}

void Print(string sentence, int shortcut) {
    if (shortcut < 0) {
        cout << sentence << '\n';
        return;
    }

    for (int i = 0; i < sentence.size(); i++) {
        if (i == shortcut) cout << '[' << sentence[i] << ']';
        else cout << sentence[i];
    }
    cout << '\n';
}

int main() {
    string tmp;
    cin >> N;
    getline(cin, tmp);
    for (int i = 0; i < N; i++) getline(cin, sentences[i]);
    
    for (int i = 0; i < N; i++) {
        shortcuts[i] = FindShortcut(sentences[i]);
    }
    for (int i = 0; i < N; i++) {
        Print(sentences[i], shortcuts[i]);
    }

    return 0;
}
