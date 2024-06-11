class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int i = 0, j = 0;
        int k = 0;


        unordered_set<int> s(arr2.begin(), arr2.end());


        map<int,int> m;
        for(int i = 0; i < arr1.size(); i++){
            m[arr1[i]]++;
        }

        for(int i = 0; i < arr2.size(); i++){
            for(int j = 0; j < m[arr2[i]]; j++){
                ans.push_back(arr2[i]);
            }
        }
        int x = ans.size();
        for(auto val : arr1){
            if(s.find(val) == s.end()){
                ans.push_back(val);
            }
        }

        sort(ans.begin()+x, ans.end());
        return ans;
    }
};