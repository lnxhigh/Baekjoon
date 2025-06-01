#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll l, n;
ll dx[4] = { +1, 0, -1, 0 };
ll dy[4] = { 0, +1, 0, -1 };

struct Point {
    ll x = 0, y = 0;
};

struct Line {
    Point from, to;
};

struct Snake {
    ll dir = 0;
    Point head = {0, 0};
    vector<Line> body = {
        {{l+1,l+1},{-l-1,l+1}}, 
        {{-l-1,l+1},{-l-1,-l-1}}, 
        {{-l-1,-l-1},{l+1,-l-1}}, 
        {{l+1,-l-1},{l+1,l+1}}
    };

    void rotate(bool ccw) {
        if (ccw) dir = (dir + 1) % 4;
        else dir = (dir + 3) % 4;
    }

    pair<bool,ll> go(ll t) {
        bool chk = false;
        ll ret = 0;

        for (const Line& line : body) {
            ll tmp = 0;

            if (dir == 0) {
                if ((head.y - line.from.y) * (head.y - line.to.y) <= 0) {
                    tmp = min(line.from.x, line.to.x) - head.x;
                }
            }
            else if (dir == 1) {
                if ((head.x - line.from.x) * (head.x - line.to.x) <= 0) {
                    tmp = min(line.from.y, line.to.y) - head.y;
                }
            }
            else if (dir == 2) {
                if ((head.y - line.from.y) * (head.y - line.to.y) <= 0) {
                    tmp = head.x - max(line.from.x, line.to.x);
                }
            }
            else if (dir == 3) {
                if ((head.x - line.from.x) * (head.x - line.to.x) <= 0) {
                    tmp = head.y - max(line.from.y, line.to.y);
                }
            }

            if (tmp > 0) {
                chk = (tmp <= t);
                ret = (ret) ? min(ret, tmp) : tmp;
            }
        }

        return { chk, ret };
    }
};

int main() {
    FastIO
    cin >> l >> n;

    Snake snake;
    ll ans = 0;
    bool died = false;
    
    for (ll i = 0; i <= n; i++) {
        ll t = 0;
        char dir = 'L'; 
        
        if (i < n) cin >> t >> dir;
        else t = l * 2 + 2;
        
        if (died) continue;

        auto [chk, ret] = snake.go(t);
        
        if (chk) {
            ans += ret;
            died = true;
        }
        else {
            ans += t;
            Point from = { snake.head.x, snake.head.y };
            Point to = { snake.head.x + t * dx[snake.dir], snake.head.y + t * dy[snake.dir] };
            Line body = { from, to };
            
            snake.rotate(dir == 'L');
            snake.head = to;
            snake.body.push_back(body);
        }
    }

    cout << ans << '\n';
    return 0;
}
