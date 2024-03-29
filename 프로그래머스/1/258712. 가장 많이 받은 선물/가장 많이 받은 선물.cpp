#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int graph[50][50] = {0,};
map<string,int> name_to_index;
map<int,string> index_to_name;
int gift_index[50] = {0,};
int gift_expected[50] = {0,};

int solution(vector<string> friends, vector<string> gifts) {
    const int N = friends.size();
    for (int i = 0; i < N; i++) {
        name_to_index[friends[i]] = i;
        index_to_name[i] = friends[i];
    }
    
    for (string gift : gifts) {
        stringstream ss(gift);
        string from, to;
        ss >> from >> to;
        
        int f, t;
        f = name_to_index[from];
        t = name_to_index[to];
        
        graph[f][t]++;
        gift_index[f]++;
        gift_index[t]--;
    }
    
    for (int from = 0; from < N; from++) {
        for (int to = 0; to < N; to++) {
            if (from == to) continue;
            
            int f = graph[from][to];
            int t = graph[to][from];
            
            if (f > t) gift_expected[from]++;
            else if (f == t) {
                int fi = gift_index[from];
                int ti = gift_index[to];
                if (fi > ti) gift_expected[from]++;
            }
        }
    }
    
    int answer = *max_element(gift_expected, gift_expected + N);
    
    return answer;
    
    
    
    /*
    누가 선물을 많이 받을지
    선물을 주고받은 기록이 있다면 더 많은 선물을 준 사람이 다음달에 받는다
        
        기록이 없거나 주고받은수가 같다면 선물지수가 더큰사람이 작은 사람에게 선물으받는다
        선물지수는 준선물수 - 받은선물수 
        선물지수까지 같으면 선물을 주고받지 않는다
        그래프문제삘
        
        선물을가장많이받을 친구의 선물수
     */  
        
        
}