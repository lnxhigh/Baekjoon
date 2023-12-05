#include <iostream>
#include <vector>
#include <algorithm>
#define N_MAX 10001
using namespace std;

int N, M;
vector<int> arr;
vector<int> seq;

int selection[N_MAX] = {0,};

void print(int cnt) {
    if (cnt == M) {
        for (auto k : seq) {
            cout << k << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (selection[arr[i]] > 0) {
            selection[arr[i]]--;
            seq.push_back(arr[i]);
            print(cnt+1);
            selection[arr[i]]++;
            seq.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;

    for (int i = 0 ; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        selection[x]++;
    }

    sort(arr.begin(), arr.end());
    arr.erase( unique(arr.begin(), arr.end()), arr.end() );
    
    N = arr.size();

    print(0);

    return 0;
}
