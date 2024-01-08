#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int personKnowTheTruth[51] = {0,};
int partyKnowTheTruth[51] = {0,};
vector<vector<int>> party(51);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    cin >> K;
    for (int k = 1; k <= K; k++) {
        int person;
        cin >> person;
        personKnowTheTruth[person] = 1;
    }
    
    for (int i = 1; i <= M; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            int person;
            cin >> person;
            party[i].push_back(person);
        }
    }


    for (int i = 1; i <= M; i++) {
        for (int x : party[i]) {
            if (personKnowTheTruth[x] == 1) {
                partyKnowTheTruth[i] = 1;
            }
        }
    }

    for (int k = 1; k <= M; k++) {
        for (int i = 1; i <= M; i++) {
            if (partyKnowTheTruth[i] == 1) {
                for (int x : party[i]) {
                    personKnowTheTruth[x] = 1;
                }
            }
        }
        
        for (int i = 1; i <= M; i++) {
            for (int x : party[i]) {
                if (personKnowTheTruth[x] == 1) {
                    partyKnowTheTruth[i] = 1;
                }
            }       
        }      

    }

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        if (partyKnowTheTruth[i] == 0) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}