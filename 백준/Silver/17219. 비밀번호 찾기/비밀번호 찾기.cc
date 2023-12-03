#include <iostream>
#include <map>
#include <string>
using namespace std;

int N, M;
string site, password;
map<string,string> info;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> site >> password;
        info[site] = password;
    }

    for (int i = 0; i < M; i++) {
        cin >> site;
        cout << info[site] << '\n';
    }
    
    return 0;
}