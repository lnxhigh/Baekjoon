#include <bits/stdc++.h>
using namespace std;

string type;
unordered_map<string,int> counts;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(4);

    int total = 0;
    while (getline(cin, type)) {
        total++;
        counts[type]++;
    }

    vector<string> species;
    species.reserve(counts.size());
    for (const auto &p : counts) { species.push_back(p.first); }
    sort(species.begin(), species.end());

    for (const string &s : species) {
        double p = (double) counts[s] * 100.0 / (double) total;
        cout << s << ' ' << p << '\n';
    }
    
    return 0;
}
