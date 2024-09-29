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
}