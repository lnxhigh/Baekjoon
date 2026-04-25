#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
      
    cin >> N >> M;

    map<string,int> index;
    map<int,string> name;
    string pocketmon;
    string query;

    for (int i = 1; i <= N; i++) {
        cin >> pocketmon;
        index[pocketmon] = i;
        name[i] = pocketmon;
    }

    for (int i = 1; i <= M; i++) {
        cin >> query;
        char c = query[0];
        bool number = false;
        
        if (c >= 48 and c <= 57) number = true;
        if (number) cout << name[stoi(query)] << '\n';
        else cout << index[query] << '\n';
    }

    return 0;
}