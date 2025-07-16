class Solution {
    bool isSatisfying(vector<int> &freq){
        for(int i = 0; i < 256; i++){
            if(freq[i] > 0){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        vector<int> freq(256); //'a' 97 to 97+25 and 'A' 65
        for(auto &ch : t){
            freq[ch]++;  //freq['A'] = 1 for "ABC"
        }
        int l = 0, r = n;
        int left = 0;
        bool ansFound = false;
        for(int right = 0; right < n; right++){
            freq[s[right]]--;
            while(isSatisfying(freq) && left <= right){
                if(right-left+1 < r-l+1){
                    l = left;
                    r = right;
                    // cout<<left<<" "<<right<<endl;
                    ansFound = true;
                }
                freq[s[left]]++;
                left++;
            }
        }
        // cout<<l<<" "<<r<<endl;
        if(ansFound == false)return "";
        return s.substr(l, r-l+1);
    }
};
// O(nsq *  256)