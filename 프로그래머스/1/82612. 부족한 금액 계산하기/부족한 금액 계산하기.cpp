using namespace std;

long long solution(int price, int money, int count)
{
    long long total = (price * 1LL) * (count * 1LL) * (count * 1LL + 1LL) / 2LL;
    long long answer = money - total;
    
    if (money > total) answer = 0LL;
    else answer = total - money;

    return answer;
}