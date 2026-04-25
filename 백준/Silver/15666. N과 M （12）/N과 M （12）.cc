#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define MAX 8

using namespace std;

int N_, N, M;
int seq_[MAX];
vector<int> seq;
int arr[MAX];
int temp[MAX] = {0,};
map<int,bool> check;

bool promising(int i, int next) {
    if (next == 0) return true;

    if (seq[i] >= seq[arr[next-1]]) return true;
    else return false;
}

void print(int next) {
    if (next == M) {

        int k = 0;
        bool same = true;
    
        for (int i = 0; i < M; i++) {
            if (seq[temp[i]] != seq[arr[i]]) {
                k = i;
                same = false;
                break;
            }
        }
        
        for (int j = k; j < M; j++) {
            temp[j] = arr[j];
        }

        if (same) return;
        
        for (int i = 0; i < M; i++) {   
            cout << seq[arr[i]] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = 0; i < N; i++) {
        if (promising(i, next)) {
            arr[next] = i;
            print(next+1);
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N_ >> M;
    for (int i = 0; i < N_; i++) {
        cin >> seq_[i];
    }
    sort(seq_, seq_ + N_);
    
    for (int i = 0; i < N_; i++) {

        if (check[seq_[i]]) continue;
        check[seq_[i]] = true;
        seq.push_back(seq_[i]);
    }

    N = seq.size();
    for (int i = 0; i < M; i++) cout << seq[0] << " ";
    cout << '\n';
    print(0);

    return 0;
}