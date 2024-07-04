class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> available;
        queue<pair<string,int>> q;

        q.push({beginWord, 0});
        for(auto str : wordList){
            available[str] = 1;
        }
        available[beginWord] = 0;

        while(!q.empty()){

            string tp = q.front().first;
            int dis = q.front().second;
            q.pop();

            if(tp == endWord){
                return dis+1;
            }

            for(char ch = 'a'; ch <= 'z'; ch++){
                for(int i = 0; i < tp.size(); i++){
                    char curr = tp[i];
                    tp[i] = ch;

                    if(available[tp]){
                        q.push({tp,dis+1});
                        available[tp] = 0;
                    }

                    tp[i] = curr;
                }
            }

        }

        return 0;
    }
};