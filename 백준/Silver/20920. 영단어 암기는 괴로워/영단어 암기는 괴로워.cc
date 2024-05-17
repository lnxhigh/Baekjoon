#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> words;
unordered_map<string,int> wordFreq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if (word.size() >= M) {
            if (!wordFreq.count(word)) {
                words.push_back(word);
            }
            wordFreq[word]++;
        }
    }

    sort(words.begin(), words.end(), [] (string &left, string &right) {
        if (wordFreq[left] != wordFreq[right]) return wordFreq[left] > wordFreq[right];
        if (left.size() != right.size()) return left.size() > right.size();

        return left < right;
    });

    for (string word : words) {
        cout << word << '\n';
    }

    return 0;
}
