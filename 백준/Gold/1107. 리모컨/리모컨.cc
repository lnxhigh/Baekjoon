#include <bits/stdc++.h>
using namespace std;

//0244
const int START = 100;
int N, K;
bool visited[1 << 20];
bool isBroken[10];
vector<int> notBroken;

vector<int> V;
int closest = 100;

void f(int N, int K) {
    if (V.size() == K) {
        if (K == 0) return;
        int newClosest = 0;
        int mul = 1;
        for (int i = 0; i < K; i++) {
            newClosest += V[i] * mul;
            mul *= 10;
        }

        if (abs(closest - N) > abs(newClosest - N)) {
            closest = newClosest;
        }
        else if (abs(closest - N) == abs(newClosest - N)) {
            if (newClosest < closest) closest = newClosest;
        }

        return;
    }

    for (int i : notBroken) {
        V.push_back(i);
        f(N, K);
        V.pop_back();
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int X;
        cin >> X;
        isBroken[X] = true;
    }
    for (int i = 0; i < 10; i++) {
        if (!isBroken[i]) notBroken.push_back(i);
    }

    int S = to_string(N).size();
    for (int i : { -1, 0, +1 }) f(N, S + i);

    int pm = abs(N - START);
    int button = abs(closest - N) + to_string(closest).size();
    int res = min(pm, button);
    cout << res << '\n';

    return 0;
}
