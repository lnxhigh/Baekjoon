#include <bits/stdc++.h>
using namespace std;
using Point = pair<int,int>;

map<Point,bool> V;
map<pair<Point,Point>,bool> E;

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void update(Point &cur, int i, int &vertex, int &edge) {
    auto [x, y] = cur;
    Point next = { x + dx[i], y + dy[i] };
    if (!V[next]) {
        V[next] = true;
        vertex++;
    }

    if (!E[{ cur,next }] || !E[{ next,cur }]) {
        E[{ cur,next }] = E[{ next,cur }] = true;
        edge++;
    }

    cur = next;
}

int solution(vector<int> arrows) {
    const int N = (int) arrows.size();
    int vertex = 0, edge = 0, face = 0;
    
    Point cur = { 0, 0 };
    V[cur] = true;
    vertex++;
    
    for (int i = 0; i < N; i++) {
        int dir = arrows[i];
        update(cur, dir, vertex, edge);
        update(cur, dir, vertex, edge);
    }
    
    face = edge - vertex + 1;
    return face;
}
