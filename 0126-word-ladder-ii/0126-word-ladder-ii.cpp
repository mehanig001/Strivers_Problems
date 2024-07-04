class Solution {
private:
    void dfs(string curr, vector<string> &v, vector<vector<string>> &ans, string beginWord, map<string,int> &m){
        int dis = m[curr];
        if(curr == beginWord){
            reverse(v.begin(), v.end());
            ans.push_back(v);
            reverse(v.begin(), v.end());
            return;
            
        }
        for(int i = 0; i < curr.size(); i++){
            char prev = curr[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                curr[i] = ch;
                if(m.find(curr) != m.end() && m[curr] == dis-1){
                    v.push_back(curr);
                    dfs(curr, v, ans, beginWord,m);
                    v.pop_back();
                }
                curr[i] = prev;
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //applying word ladder1 to find min steps to reach endWord but this time we will not time of occurance of each word in map
        map<string,int> m;
        queue<string> q;
        unordered_set<string> unvisited(wordList.begin(), wordList.end());

        q.push(beginWord);
        m[beginWord] = 0;
        unvisited.erase(beginWord);

        int dis = 0;
        int minDis = 1e9;


        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(curr == endWord){
                minDis = dis;
                break;
            }
            dis = m[curr];

            for(char ch = 'a'; ch <= 'z'; ch++){
                for(int i = 0; i < curr.size(); i++){
                    char prev = curr[i];
                    curr[i] = ch;
                    if(unvisited.find(curr) != unvisited.end()){
                        unvisited.erase(curr);
                        q.push(curr);
                        m[curr] = dis+1;
                    }
                    curr[i] = prev;
                }
            }
           
        }

        cout<<minDis<<endl;

        //backTrack in map from end to begin
        vector<string> v;
        v.push_back(endWord);
        vector<vector<string>> ans;
        dfs(endWord, v, ans, beginWord, m);

        return ans;
    }
};