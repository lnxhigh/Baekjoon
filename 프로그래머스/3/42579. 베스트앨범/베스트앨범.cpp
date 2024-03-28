#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define N_MAX 10000

using namespace std;

struct Song {
    string genre;
    int play;
    int index;
};

Song songs[N_MAX];
map<string,int> genre_map;
map<string,int> genre_num;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    const int N = genres.size();
    
    for (int i = 0; i < N; i++) {
        genre_num[genres[i]] = 0;
        genre_map[genres[i]] += plays[i];
        songs[i] = { genres[i], plays[i], i };
    }
    
    sort(songs, songs + N, [] (Song &left, Song &right) {
        int lg = genre_map[left.genre];
        int rg = genre_map[right.genre];
        if (lg > rg) return true;
        else if (lg == rg) {
            int lp = left.play;
            int rp = right.play;
            if (lp > rp) return true;
            else if (left.play == right.play) {
                int li = left.index;
                int ri = right.index;
                return li < ri;
            }
            else return false;
        }
        else return false;
    });
        
    
    for (int i = 0; i < N; i++) {
        if (genre_num[songs[i].genre] >= 2) continue;
        genre_num[songs[i].genre]++;
        answer.push_back(songs[i].index);
    }
    
    return answer;
}