class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        vector<int> visited(256,-1);
        int startIdx = 0; //from which string of unique item is considered
        int maxi = 0;
        
        for(int i = 0; i < n; i++){
            if(visited[s[i]] < startIdx){
                //No problem
                maxi = max((i-startIdx+1),maxi);
                visited[s[i]] = i;
            }
            else{
                //element repeat hua hai
                startIdx = visited[s[i]]+1;
                visited[s[i]] = i;
            }
        }

        return maxi;
    }
};