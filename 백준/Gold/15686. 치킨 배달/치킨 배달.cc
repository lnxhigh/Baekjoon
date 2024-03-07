#include <iostream>
#include <vector>
#define N_MAX 50
#define M_MAX 13
using namespace std;
using xy = pair<int,int>;

int N, M;
int N_chicken = 0;
int city[N_MAX][N_MAX];
int answer = 10000;

vector<xy> houses;
vector<xy> chicken_houses;
enum { FREE, HOUSE, CHICKEN };

void f(vector<int> &bits) {
    for (int bit = 0; bit < (1 << N_chicken); bit++) {
        int cnt = 0;
        for (int i = 0; i < N_chicken; i++) {
            if (bit & (1 << i)) cnt++;
        }
        if (cnt == M) bits.push_back(bit);
    }
}

void search(vector<int> &bits) {
    for (int bit : bits) {
        int res = 0;
        for (xy house : houses) {
            int min_dist = 100;
            for (int i = 0; i < N_chicken; i++) {
                if (not (bit & (1 << i))) continue;

                xy chicken_house = chicken_houses[i];
                int delta_x = house.first - chicken_house.first;
                int delta_y = house.second - chicken_house.second;
                int dist = abs(delta_x) + abs(delta_y);

                if (dist < min_dist) min_dist = dist;
            }
            res += min_dist;
        }
        
        if (res < answer) answer = res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> city[r][c];
            if (city[r][c] == HOUSE) {
                houses.push_back({r,c});
            }
            else if (city[r][c] == CHICKEN) {
                chicken_houses.push_back({r,c});
                N_chicken++;
            }
        }
    }

    vector<int> bits;
    f(bits);
    search(bits);
    cout << answer;
    
    return 0;
}