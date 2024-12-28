#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 6;
using int64 = long long;

int N, V;

struct Party {
    string name;
    int r, s, t;
    int vote;
    bool alloc;
    double p;

    Party(): r(0), s(0), t(0), vote(0), alloc(false), p(0.0) { }
};

Party P[MAX];

void input() {
    cin >> N >> V;
    for (int i = 0; i < N; i++) {
        string name; cin >> name;
        int region, vote; cin >> region >> vote;
        
        P[i].name = name;
        P[i].r = region;
        P[i].vote = vote;
    }
}

void init() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += P[i].vote;
    }

    for (int i = 0; i < N; i++) {
        P[i].alloc = (100LL * P[i].vote >= 3LL * sum) || (P[i].r >= 5);
    }
}

// 전국단위 준연동 방식으로 각 정당별 연동배분의석수 산정
void first() {
    // N: 국회의원 정수
    int n = 300;
    
    // R: 의석할당정당이 아닌 정당의 지역구 당선인 수 총합 + 무소속 지역구 당선인 수
    int r = 253;
    for (int i = 0; i < N; i++) {
        if (P[i].alloc) r -= P[i].r;
    }
    
    // p: 해당 정당의 비례대표국회의원선거 득표비율
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (P[i].alloc) sum += P[i].vote;
    }

    for (int i = 0; i < N; i++) {
        P[i].p = (double) P[i].vote / (double) sum;
    }

    // 각 정당별 연동배분의석수 산정
    for (int i = 0; i < N; i++) {
        if (!P[i].alloc) continue;
        
        double x = ((double) (n - r) * P[i].p - (double) P[i].r) / 2.0;
        P[i].s = (x >= 1) ? round(x) : 0;
    }
}

// 비례대표 의석 조정
void second() {
    int seats = 0;
    for (int i = 0; i < N; i++) {
        seats += P[i].s;
    }

    if (seats < 30) {
        int remain = 30 - seats;
        int cnt = 0;
        vector<pair<double,int>> tmp;

        for (int i = 0; i < N; i++) {
            if (!P[i].alloc) continue;
            int adj = remain * P[i].p;
            P[i].s += adj;
            cnt += P[i].s;
            
            double decimal = (double) remain * P[i].p - adj;
            tmp.push_back({ -decimal, i });
        }

        remain = 30 - cnt;
        sort(tmp.begin(), tmp.end());
        assert(remain <= (int) tmp.size());
        for (int i = 0; i < remain; i++) {
            auto [_, idx] = tmp[i];
            P[idx].s++;
        }
    }
    else if (seats > 30) {
        int cnt = 0;
        vector<pair<double,int>> tmp;

        for (int i = 0; i < N; i++) {
            if (!P[i].alloc) continue;
            double adj = 30.0 * ((double) P[i].s / (double) seats);
            P[i].s = (int) adj, cnt += (int) adj;
            
            double decimal = adj - (int) adj;
            tmp.push_back({ -decimal, i });
        }

        if (cnt < 30) {
            sort(tmp.begin(), tmp.end());
            int remain = 30 - cnt;
            assert(remain <= (int) tmp.size());
            for (int i = 0; i < remain; i++) {
                auto [_, idx] = tmp[i];
                P[idx].s++;
            }
        }
    }
}

// 17석에 대해 기존 의석배분방식 적용 배분
void third() {
    int cnt = 0;
    vector<pair<double,int>> tmp;

    for (int i = 0; i < N; i++) {
        if (!P[i].alloc) continue;
        
        double add = 17 * P[i].p;
        P[i].t = (int) add, cnt += (int) add;
        
        double decimal = add - (int) add;
        tmp.push_back({ -decimal, i });
    }

    if (cnt < 17) {
        int remain = 17 - cnt;
        sort(tmp.begin(), tmp.end());

        assert(remain <= (int) tmp.size());
        for (int i = 0; i < remain; i++) {
            auto [_, idx] = tmp[i];
            P[idx].t++;
        }
    }
}

// 결과 출력
void print() {
    vector<pair<int,string>> result;
    for (int i = 0; i < N; i++) {
        int seats = P[i].r + P[i].s + P[i].t;
        result.push_back({ -seats, P[i].name });
    }

    sort(result.begin(), result.end());
    for (auto [seats, name] : result) {
        seats = -seats;
        cout << name << ' ' << seats << '\n';
    }
}

int main() {
    FastIO
    input();
    init();
    first(); second(); third();
    print();
    return 0;
}
