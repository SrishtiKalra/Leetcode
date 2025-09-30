class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;

        q.push({beginWord,1});
        s.erase(beginWord);
        int len;

        while(!q.empty()){
            string word = q.front().first;
            len = q.front().second;
            if(word == endWord){
                return len;
            }
            q.pop();

            for(int i=0;i<word.size();i++){
               char ch = word[i];
               for(char c='a';c<='z';c++){
                    word[i] = c;
                    if(s.find(word)!=s.end()){
                        q.push({word, len+1});
                        s.erase(word);
                    }
               } 
               word[i]=ch;
            }

        }
        return 0;


    }
};