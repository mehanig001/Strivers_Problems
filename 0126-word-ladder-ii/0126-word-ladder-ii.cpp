class Solution {
private:
    void dfs(map<string, int> &m, string beginWord, vector<vector<string>>&ans, vector<string> &curr){
        string word = curr.back();

        int lvl = m[word];
        if(word == beginWord){
            reverse(curr.begin(), curr.end());
            ans.push_back(curr);
            reverse(curr.begin(), curr.end());
            return;
        }

        for(int i = 0; i < word.size(); i++){
            char prev = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(m.find(word) != m.end() &&  m[word] == lvl-1){
                    curr.push_back(word);
                    dfs(m,beginWord,ans,curr);
                    curr.pop_back();
                }
            }
            word[i] = prev;
        }
     

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        map<string, int> m;

        q.push({beginWord,0});
        m[beginWord] = 0;
        s.erase(beginWord);
       

        while(!q.empty()){
            auto pr = q.front();
            q.pop();
            string curr = pr.first;
            int lvl = pr.second;
            m[curr] = lvl;
           
            if(curr == endWord)break;

            for(int i = 0; i < curr.size(); i++){
                char prev = curr[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    curr[i] = ch;
                    if(s.count(curr) > 0){
                        q.push({curr,lvl+1});
                        s.erase(curr);
                    }
                }
                curr[i] = prev;
            }

        }
            // for(auto pr:m){
            
            //     cout<<pr.first<<" "<<pr.second<<endl;
                
            // }
            vector<vector<string>> ans;
            vector<string> curr = {endWord};

            dfs(m,beginWord,ans,curr);

            return ans;

    }
};