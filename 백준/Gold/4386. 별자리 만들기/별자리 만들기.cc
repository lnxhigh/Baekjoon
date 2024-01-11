#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

int N;
pair<float,float> star[101];
bool visited[101] = {false, };
priority_queue<pair<float,int>, vector<pair<float,int>>, greater<pair<float,int>>> pq;
vector<float> dist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        float x, y;
        cin >> x >> y;
        star[i] = {x,y};
    }

    int start = 1;

    pq.push({0.0, start});
    while (dist.size() != N) {
        pair<float,int> x = pq.top();
        pq.pop(); 
        if (visited[x.second]) { continue; }

        visited[x.second] = true;
        dist.push_back(x.first);
        pair<float,float> cur = star[x.second];
        
        for (int k = 1; k <= N; k++) {
            if (visited[k]) continue;
            
            pair<float,float> next = star[k];
            float deltaX = cur.first - next.first;
            float deltaY = cur.second - next.second;

            pq.push({ sqrt(deltaX*deltaX + deltaY*deltaY), k });
        }
    }
    
    if (dist.size() != N) {
        cout << "MST Size Error";
    }
    
    float answer = 0.0;
    for (float x : dist) {
        answer += x;
    }
    cout << answer;

    return 0;
}