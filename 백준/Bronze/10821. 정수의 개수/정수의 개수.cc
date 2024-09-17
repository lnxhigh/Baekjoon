#include <bits/stdc++.h>
using namespace std;

vector<string> split(string sentence, char delimiter) {
    int pos = -1;
    vector<string> res;
    
    while ((pos = sentence.find(delimiter)) != string::npos) {
        string word = sentence.substr(0, pos);
        res.push_back(word);
        sentence.erase(0, ++pos);
    }
    res.push_back(sentence);

    return res;
}

int main() {
    string sentence; cin >> sentence;
    vector<string> res = split(sentence, ',');
    cout << res.size() << '\n';
    return 0;
}
