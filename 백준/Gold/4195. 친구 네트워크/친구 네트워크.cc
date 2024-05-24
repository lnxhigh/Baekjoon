#include <bits/stdc++.h>
using namespace std;

string find(string s, unordered_map<string, string> &parent) {
    if (parent[s] == s) return s;
    return parent[s] = find(parent[s], parent);
}

void merge(string s, string t, 
    unordered_map<string, string> &parent, unordered_map<string, int> &network) {
    s = find(s, parent); t = find(t, parent);

    if (s == t) return;
    pair<string, string> p = (network[s] < network[t]) ? make_pair(s, t) : make_pair(t, s);
    parent[p.first] = p.second;
    network[p.second] += network[p.first];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int F;
        cin >> F;
        vector<pair<string,string>> friends;
        unordered_set<string> names;
        unordered_map<string, string> parent;
        unordered_map<string, int> network;

        for (int f = 0; f < F; f++) {
            string first, second;
            cin >> first >> second;
            friends.push_back({ first, second });
            names.insert(first); names.insert(second);
        }

        for (string name : names) {
            parent[name] = name;
            network[name] = 1;
        }

        for (int f = 0; f < F; f++) {
            merge(friends[f].first, friends[f].second, parent, network);
            string root = find(friends[f].first, parent);

            cout << network[root] << '\n';
        }
    }
    
    return 0;
}
