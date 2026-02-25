#include <string>
#include <vector>

using namespace std;
const int MAX = 101010;

int dart[MAX];
int count[MAX];

vector<int> solution(int target) {
    // Init
    for (int x = 0; x <= target; x++) {
        dart[x] = x;
    }
    
    // Compute
    for (int x = 0; x < target; x++) {
        // 불
        if (dart[x + 50] > dart[x] + 1) {
            dart[x + 50] = dart[x] + 1;
            count[x + 50] = count[x] + 1;
        } else if (dart[x + 50] == dart[x] + 1) {
            count[x + 50] = max(count[x + 50], count[x] + 1);
        }
        
        // 싱글
        for (int i = 1; i <= 20; i++) {
            if (dart[x + i] > dart[x] + 1) {
                dart[x + i] = dart[x] + 1;
                count[x + i] = count[x] + 1;
            } else if (dart[x + i] == dart[x] + 1) {
                count[x + i] = max(count[x + i], count[x] + 1);
            }
        }
        
        // 더블 / 트리플
        for (int i = 1; i <= 20; i++) {
            for (int m = 2; m <= 3; m++) {
                if (dart[x + i * m] > dart[x] + 1) {
                    dart[x + i * m] = dart[x] + 1;
                    count[x + i * m] = count[x];
                } else if (dart[x + i * m] == dart[x] + 1) {
                    count[x + i * m] = max(count[x + i * m], count[x]);
                }   
            }
        }
    }
    
    vector<int> answer = { dart[target], count[target] };
    return answer;
}
