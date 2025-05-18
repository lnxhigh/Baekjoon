#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N = 0;
    int K = 0;
    cin >> N >> K;

    

    int pos_array[201] = { 0, }; // 각 컨베이어 위치 지표
    vector<int> robot_order(0, 0); // 로봇 들어온 순서
    int Ai[201] = { 0, }; // 컨베이어 내구도
    int robot_exist[201] = { 0, }; // 각 컨베이어에 로봇 개수

    // 내구도 입력
    for (int i = 1; i <= 2 * N; i++)
    {
        cin >> Ai[i];
    }

    // 위치 초기화
    for (int i = 1; i <= 2 * N; i++)
    {
        pos_array[i] = i;
    }

    int step = 0;
    int IsLoopStart = 1;

    while (IsLoopStart)
    {
        step++; // 단계 


        // 1번. 컨베이어 회전
        for (int i = 1; i <= 2 * N; i++)
        {
            pos_array[i] = ((pos_array[i] == 1) ? 2 * N : pos_array[i] - 1);
        }

        
        // N번 위치에 로봇 내리기
        
        if (robot_exist[pos_array[N]] >= 1) 
        {
            for (int i = 0; i < robot_order.size(); i++)
            {
                if (robot_order[i] == pos_array[N])
                {
                    robot_order.erase(robot_order.begin() + i);
                }
            }

            robot_exist[pos_array[N]] = 0; 
        }

        // 2번.
        for (int i = 0; i < robot_order.size(); i++)
        {
            int next_num = ((robot_order[i] == 2 * N) ? 1 : robot_order[i] + 1);
            if (robot_exist[next_num] == 0 && Ai[next_num] >= 1)
            {
                Ai[next_num] -= 1;
                robot_exist[next_num] = 1; 
                robot_exist[robot_order[i]] -= 1; 
                robot_order[i] = next_num;
            }
        }

        // 한 번 더 로봇 내리기
        
        if (robot_exist[pos_array[N]] >= 1) 
        {
            for (int i = 0; i < robot_order.size(); i++)
            {
                if (robot_order[i] == pos_array[N])
                {
                    robot_order.erase(robot_order.begin() + i);
                }
            }

            robot_exist[pos_array[N]] = 0; 
        }

        // 3번.
        // 1번 위치 컨베이어에 로봇 올리기
        if (Ai[pos_array[1]] >= 1)
        {
            robot_order.push_back(pos_array[1]);
            robot_exist[pos_array[1]] += 1; 
            Ai[pos_array[1]] -= 1;
        }

      

        // 4번. 
        int count = 0;
        for (int i = 1; i <= 2 * N; i++)
        {
            if (Ai[i] == 0)
            {
                count++;
            }
        }

        if (count >= K)
        {
            IsLoopStart = 0;
        }
    }

    cout << step;
}