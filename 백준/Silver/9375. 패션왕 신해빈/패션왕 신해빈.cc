#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int T, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;
        string name, type;
        vector<string> names;
        vector<string> types;
        map<string,int> count;
        for (int i = 0; i < N; i++) {
            cin >> name >> type;

            bool nameDuplicated = false;
            for (string x : names) {
                if (name == x) nameDuplicated = true;
            }
            if (not nameDuplicated) names.push_back(name);

            count[type]++;

            bool typeDuplicated = false;
            for (string x : types) {
                if (type == x) typeDuplicated = true;
            }
            if (not typeDuplicated) types.push_back(type);
        }

        int ans = 1;
        for (string x : types) {
            ans *= count[x]+1;
        }

        ans--;
        cout << ans << '\n';
    }
    
    return 0;
}