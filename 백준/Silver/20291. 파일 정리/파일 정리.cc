#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N;
map<string,int> extensions;

string extract(string name) {
    int pos = name.find('.');
    string ext = name.substr(++pos);
    return ext;
}

int main() {
    FastIO
    cin >> N;
    while (N--) {
        string fileName;
        cin >> fileName;
        
        string ext = extract(fileName);
        extensions[ext]++;
    }

    for (auto p : extensions) {
        string name = p.first;
        int cnt = p.second;
        cout << name << ' ' << cnt << '\n';
    }
    return 0;
}
