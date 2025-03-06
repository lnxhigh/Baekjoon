#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
string L;
int F;

int Month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int f(const string &ymd, const string &hm) {
    int year = stoi(ymd.substr(0, 4));
    assert(year == 2021);

    int mon = stoi(ymd.substr(5, 2));
    int day = stoi(ymd.substr(8, 2));
    
    int hour = stoi(hm.substr(0, 2));
    int min = stoi(hm.substr(3, 2));

    int sum = day;
    for (int i = 1; i < mon; i++) sum += Month[i];
    sum *= 24, sum += hour;
    sum *= 60, sum += min;

    return sum;
}

struct Person {
    map<string,vector<int>> time;
};

int main() {
    FastIO
    cin >> N >> L >> F;
    
    map<string,Person> people;

    // Input
    while (N--) {
        string ymd, hm, P, M; 
        cin >> ymd >> hm >> P >> M;

        if (people.find(M) == people.end()) people[M] = Person();
        int t = f(ymd, hm);
        people[M].time[P].push_back(t);
    }

    // Parse L
    int d = stoi(L.substr(0, 3));
    int h = stoi(L.substr(4, 2));
    int m = stoi(L.substr(7, 2));
    int duration = (d * 24 + h) * 60 + m;

    // Result
    long long total = 0;
    map<string,long long> fine;

    for (auto& [name, person] : people) {
        for (auto& [p, vec] : person.time) {
            sort(vec.begin(), vec.end());
        }

        for (auto& [p, vec] : person.time) {
            for (int i = 0; i < (int) vec.size(); i += 2) {
                int diff = vec[i + 1] - vec[i];
                if (diff <= duration) continue;

                int excess = diff - duration;
                long long cost = (long long) excess * F;

                total += cost;
                fine[name] += cost;
            }
        }
    }
    
    if (total == 0) {
        cout << -1 << '\n';
    }
    else {
        for (auto [name, value] : fine) {
            cout << name << ' ' << value << '\n';
        }
    }

    return 0;
}
