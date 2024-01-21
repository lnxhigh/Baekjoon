#include <iostream>
#include <utility>
#include <set>
using namespace std;

int N;
int A[100001], i, v;
int M, query;
set<pair<int,int>> S; // <v,i> pair

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S.insert({A[i],i});
    }

    cin >> M; 
    
    for (int m = 0; m < M; m++) {
        cin >> query;
        if (query == 1) {
            cin >> i >> v;
            S.erase({A[i],i});
            A[i] = v;
            S.insert({A[i],i});

        }
        else if (query == 2) {
            pair<int,int> front = *S.begin();
            cout << front.second << '\n';
        }
        else {
            cerr << "Query Error" << '\n';
        }
    }
    
    return 0;
}