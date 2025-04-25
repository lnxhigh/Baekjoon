#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
string document;

vector<string> parse(const string &str) {
    vector<string> ret;

    int idx = 0;
    int len = str.size();

    while (idx < len) {
        while (idx < len && str[idx] == ' ') idx++;

        string word;
        while (idx < len && str[idx] != ' ') word.push_back(str[idx++]);
        
        ret.push_back(word);
    }

    return ret;
}

int main() {
    FastIO
    
    getline(cin, document);
    n = document.size();

    int ptr = 0;
    string paragraph;

    assert(document[0] != ' ');

    while (ptr < n) {
        if (document[ptr] == '<') {
            string content;
            while (document[ptr] != '>') {
                content.push_back(document[++ptr]);
            }
            ++ptr;
            content.pop_back();

            int x = 0;
            while (x < (int) content.size() && content[x] == ' ') x++;

            string tagname;
            while (x < (int) content.size() && content[x] != ' ') tagname.push_back(content[x++]);
            while (x < (int) content.size() && content[x] == ' ') x++;

            if (tagname == "/p") {
                vector<string> words = parse(paragraph);
                int len = words.size();

                for (int i = 0; i < len; i++) {
                    cout << words[i];
                    if (i != len - 1) cout << ' ';
                }
                cout << '\n';

                paragraph.clear();
            }
            else if (tagname == "div") {
                if (x < (int) content.size()) {
                    // attribute 가 하나임을 가정함 
                    // 안 되면 어떤 식으로 구현해야 할지 모르겠다
                    string cur = content.substr(x);
                    int idx = 0;
                    while (idx < (int) cur.size() && cur[idx] != '=') idx++;
                    
                    // attribute 와 value 사이 띄어쓰기가 없음을 가정함
                    string attribute = cur.substr(0, idx);
                    if (attribute != "title") continue;

                    int last = cur.size();
                    while (last >= 0 && cur[last] != '"') last--;

                    string value = cur.substr(idx + 2, last- idx - 2);
                    cout << "title : " << value << '\n';
                }
            }
        }
        else {
            paragraph.push_back(document[ptr++]);
        }
    }

    return 0;
}
