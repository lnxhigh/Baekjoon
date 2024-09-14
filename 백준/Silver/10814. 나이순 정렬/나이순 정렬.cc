#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

struct Info {
    int age;
    int time;
    string name;
};

int main() {
    FastIO
    int N; cin >> N;
    vector<Info> members(N);
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        members[i] = { age, i, name };
    }

    sort(members.begin(), members.end(), [] (const Info &left, const Info &right) {
        if (left.age != right.age) return left.age < right.age;
        return left.time < right.time;
    });

    for (const Info &member : members) {
        cout << member.age << ' ' << member.name << '\n';
    }
    return 0;
}
