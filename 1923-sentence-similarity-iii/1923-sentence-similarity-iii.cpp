class Solution {
    vector<string> words(string str){
        vector<string> ans;
        int n = str.size();
        string word = "";
        for(int i = 0; i < n; i++){
            if(str[i] == ' ' || i == n-1){
                if(i == n-1)word += str[n-1];
                ans.push_back(word);
                word = "";
            }
            else{
                word += str[i];
            }
        }
        return ans;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = words(sentence1);
        vector<string> s2 = words(sentence2);

        for(auto word : s1)cout<<word<<" ";cout<<endl;
        for(auto word : s2)cout<<word<<" ";cout<<endl;
        
        if(s1.size() < s2.size()){
            swap(s1, s2);
        }

        int n = s1.size();
        int m = s2.size();

        int si = 0, ei = 0;
        while(si < m && s1[si] == s2[si])si++;
        while(ei < m && s1[n-ei-1] == s2[m-ei-1])ei++;

        return si + ei >= m;

    }
};