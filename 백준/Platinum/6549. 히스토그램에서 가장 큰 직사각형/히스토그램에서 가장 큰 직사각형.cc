#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll start, ll end, const vector<ll> &heights) {
    if (start == end) return heights[start];

    // Left Area, Right Area - Divide and Conquer
    ll mid = start + (end - start) / 2LL;
    ll leftArea = solve(start, mid, heights);
    ll rightArea = solve(mid+1, end, heights);
    
    // Mid Area - Two Pointer
    ll midArea;
    ll left = mid, right = mid+1;
    ll minHeight = min({heights[left], heights[right]});
    ll maxArea = minHeight * (right - left + 1);

    while (true) {
        if (left == start && right == end) break;

        bool moveToLeft;
        if (left == start) moveToLeft = false;
        else if (right == end) moveToLeft = true;
        else moveToLeft = (heights[left-1] > heights[right+1]);
        
        ll newHeight = moveToLeft ? heights[--left] : heights[++right];
        minHeight = min({minHeight, newHeight});
        
        ll newArea = minHeight * (right - left + 1);
        maxArea = max({maxArea, newArea});   
    }

    midArea = maxArea;

    // Take the maximum of three
    return max({leftArea, midArea, rightArea});
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    while (true) {
        ll N;
        std::cin >> N;
        if (N == 0) break;
        
        vector<ll> heights;
        for (ll i = 0; i < N; i++) {
            ll h;
            std::cin >> h;
            heights.push_back(h);
        }

        ll answer = solve(0, N-1, heights);
        std::cout << answer << '\n';
    }

    return 0;
}
