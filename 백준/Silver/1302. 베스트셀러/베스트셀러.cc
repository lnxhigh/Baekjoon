#include <bits/stdc++.h>
using namespace std;
using info = pair<string,int>;

int N;
unordered_map<string,int> books;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string title;
        cin >> title;
        books[title]++;
    }

    vector<info> res;
    for (const info &p : books) res.push_back(p);
    sort(res.begin(), res.end(), [] (info &left, info &right) {
        if (left.second != right.second) return left.second > right.second;
        return left.first < right.first;
    });

    info best = *res.begin();
    string title = best.first;
    cout << title << '\n';

    return 0;
}
