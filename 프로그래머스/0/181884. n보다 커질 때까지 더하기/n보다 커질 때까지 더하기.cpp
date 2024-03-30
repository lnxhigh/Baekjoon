#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    const int N = numbers.size();
    int sum = 0;
    for (int number : numbers) {
        sum += number;
        if (sum > n) break;
    }
    return sum;
}