#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

struct node {
    int x, y;
    node *prvX, *nxtX, *prvY, *nxtY;
    
    node(int __x, int __y): x(__x), y(__y) {
        prvX = nxtX = prvY = nxtY = nullptr;
    }
};

int N, K;
string query;

map<int,set<int>> mapX, mapY;
map<pair<int,int>,node*> mapNode;

int main() {
    FastIO
    cin >> N >> K;
    cin >> query;

    node* cur = nullptr;

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        int s = x - y, t = x + y;
        
        pair<int,int> p = { s, t };
        mapNode[p] = new node(s, t);
        if (i == 0) cur = mapNode[p];

        mapX[s].insert(t);
        mapY[t].insert(s);
    }

    for (const auto& [x, s] : mapX) {
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            if (next(iter) == s.end()) continue;
            
            pair<int,int> p = { x, *iter };
            pair<int,int> q = { x, *next(iter) };
            mapNode[p]->nxtY = mapNode[q];
            mapNode[q]->prvY = mapNode[p];
        }
    }

    for (const auto& [y, s] : mapY) {
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            if (next(iter) == s.end()) continue;
            
            pair<int,int> p = { *iter, y };
            pair<int,int> q = { *next(iter), y };
            mapNode[p]->nxtX = mapNode[q];
            mapNode[q]->prvX = mapNode[p];
        }
    }

    for (char q : query) {
        node* nxt = nullptr;

        if (q == 'A') nxt = cur->nxtY; // up
        else if (q == 'B') nxt = cur->nxtX; // right
        else if (q == 'C') nxt = cur->prvX; // left
        else if (q == 'D') nxt = cur->prvY; // down

        if (nxt) {
            // delete
            if (cur->prvY) cur->prvY->nxtY = cur->nxtY;
            if (cur->nxtY) cur->nxtY->prvY = cur->prvY;
            if (cur->prvX) cur->prvX->nxtX = cur->nxtX;
            if (cur->nxtX) cur->nxtX->prvX = cur->prvX;

            // update
            cur = nxt;
        }
    }

    long long x = (long long) (cur->x + cur->y) / 2;
    long long y = (long long) (cur->y - cur->x) / 2;
    cout << x << ' ' << y << '\n';

    return 0;
}
