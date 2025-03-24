#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;
vector<string> S;

int main() {
    FastIO
    S.reserve(MAX);

    while (true) {
        string word; cin >> word;
        if (word == "-") break;
        S.push_back(word);
    }

    while (true) {
        string puzzle; cin >> puzzle;
        if (puzzle == "#") break;

        int mincnt = S.size();
        int maxcnt = 0;
        int result[9][2] = {0};

        for (int i = 0; i < 9; i++) {
            int cnt = 0;

            for (const string& word : S) {
                if (word.find(puzzle[i]) == string::npos) continue;
                
                int D[26] = {0};
                bool flag = true;

                for (char alpha : puzzle) {
                    D[(int)(alpha - 'A')]++;
                }
                for (char alpha : word) {
                    if (D[(int)(alpha - 'A')]-- == 0) {
                        flag = false;
                        break;
                    }
                }

                if (flag) cnt++;
            }

            mincnt = min(mincnt, cnt);
            maxcnt = max(maxcnt, cnt);
            result[i][0] = cnt;
            result[i][1] = cnt;
        }

        set<char> minResult, maxResult;
        for (int i = 0; i < 9; i++) {
            if (result[i][0] == mincnt) minResult.insert(puzzle[i]);
            if (result[i][1] == maxcnt) maxResult.insert(puzzle[i]);
        }

        for (char alpha : minResult) cout << alpha;
        cout << ' ' << mincnt << ' ';
        for (char alpha : maxResult) cout << alpha;
        cout << ' ' << maxcnt << '\n';
    }
    
    return 0;
}
