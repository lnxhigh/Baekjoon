#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    for (int num : num_list)
        if (n == num) return 1;
    return 0;
}