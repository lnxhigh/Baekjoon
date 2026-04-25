#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N, M;
vector<string> people;
map<string,bool> hear;
map<string,bool> look;
string person;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    people.reserve(N+M);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> person;
        hear[person] = true;
        people.push_back(person);
    }
    for (int i = 0; i < M; i++) {
        cin >> person;
        look[person] = true;
        people.push_back(person);
    }

    sort(people.begin(), people.end());
    people.erase(unique(people.begin(), people.end()), people.end());

    vector<string> hear_and_look;

    for (string person : people) {
        if (hear[person] and look[person]) {
            hear_and_look.push_back(person);
        }
    }

    cout << hear_and_look.size() << '\n';
    for (string person : hear_and_look) {
        cout << person << '\n';
    }

    return 0;
}