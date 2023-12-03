#include <iostream>
#include <string>
#include <vector>
#define INF 2147483647
using namespace std;

int T, N;
string MBTI;

int encode(string MBTI) {
    int I, N, T, J;
    I = (MBTI[0] == 'I');
    N = (MBTI[1] == 'N');
    T = (MBTI[2] == 'T');
    J = (MBTI[3] == 'J');

    return (I << 3) + (N << 2) + (T << 1) + (J << 0);
}

int Min(int x, int y) { return x < y ? x : y ; }
int Abs(int x) { return x > 0 ? x : -x ; }
int bit(int x, int N) { return (x & (1 << N)) >> N; }

int dist(int x, int y) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += Abs(bit(x, i) - bit(y, i));
    }
    return sum;
}

int dist(int x, int y, int z) {
    return dist(x, y) + dist(y, z) + dist(z, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for (int t = 0; t < T; t++) {
        int answer = INF;
        bool zero = false;
        int type[16] = {0,};
        vector<int> personality;
        
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> MBTI;
            type[encode(MBTI)]++;
        }
        
        for (int i = 0; i < 16; i++) {
            if (type[i] >= 3) { 
                zero = true; 
                break; 
            }
            for (int k = 0; k < type[i]; k++) {
                personality.push_back(i);
            }
        }

        if (zero) {
            cout << 0 << '\n';
            continue;
        }

        int s = personality.size();
        for (int i = 0; i < s; i++) {
            for (int j = i+1; j < s; j++) {
                for (int k = j+1; k < s; k++) {
                    answer = Min(answer, dist(personality[i],personality[j], personality[k]));
                }
            }
        }

        cout << answer << '\n';
    }
    
    return 0;
}