#include <bits/stdc++.h>
using namespace std;

string word;

int main() {
    cin >> word;
    for (char c : word) {
        if      (c >= 'a' && c <= 'z') cout << (char) toupper(c);
        else if (c >= 'A' && c <= 'Z') cout << (char) tolower(c);
    }
    
    cout << '\n';
    return 0;
}
