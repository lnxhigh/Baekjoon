#include <bits/stdc++.h>

using namespace std;

long long solution(int capacity, int n, vector<int> deliveries, vector<int> pickups) {
    long long t = 0;
    priority_queue<pair<int,int>> front, back;
    
    for (int i = 0; i < n; i++) {
        int x = deliveries[i];
        int y = pickups[i];
        if (x > 0) front.push({ i + 1, x });
        if (y > 0) back.push({ i + 1, y });
    }

    while (not front.empty() or not back.empty()) {
        // Deliver
        int cnt = capacity;
        int dist = 0;
        
        while (cnt > 0 and not front.empty()) {
            auto [x, rest] = front.top();
            front.pop();
            
            dist = max(dist, x);
            int boxes = min(cnt, rest);
            cnt -= boxes, rest -= boxes;
            
            if (rest > 0) front.push({ x, rest });
        }
        
        cnt = capacity;
        
        // Pickup
        int delta = 0;
        
        while (cnt > 0 and not back.empty()) {
            auto [x, rest] = back.top();
            back.pop();
            
            delta = max(delta, x - dist);
            
            int boxes = min(cnt, rest);
            cnt -= boxes, rest -= boxes;
            
            if (rest > 0) back.push({ x, rest });
        }
        
        int len = dist + delta;
        t += len * 2;
    }
    
    return t;
}
