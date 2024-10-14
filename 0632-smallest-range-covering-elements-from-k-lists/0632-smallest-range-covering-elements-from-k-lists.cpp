class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = n;
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            for(auto ele : nums[i]){
                v.push_back({ele, i});
            }
        }

        sort(v.begin(), v.end());

        for(auto pr : v)cout<<pr.first<<" "<<pr.second<<endl;

        map<int, int> mp;
        n = v.size();

        int si = 0, ei = 0;
        int asi = 0;
        int aei = n-1;
        int diff = v[aei].first - v[asi].first;

        while(mp.size() < m && ei < n){
            mp[v[ei].second]++;
            ei++;
        }

        cout<<"printing first window"<<endl;
        for(auto pr : mp){
            cout<<pr.first<<" "<<pr.second<<endl;
        }

        // if(ei == n){
        //     return {v[asi].first, v[aei].first};
        // }
        
        ei--;
        int newdiff = (v[ei].first - v[si].first);
        if(newdiff < diff){
            asi = si;
            aei = ei;
            diff = newdiff;
        }
        

        while(ei < n){
            cout<<"si: "<<si<<" ei: "<<ei<<endl;
            int state = v[si].second;
            mp[state]--;
            
            if(mp[state] == 0){
                mp.erase(state);
                while(ei+1 < n &&  mp.size() != m){
                    ei++;
                    mp[v[ei].second]++;
                }
            }

            si++;
            if(ei == n || si == n)break;
            
            int newdiff = (v[ei].first - v[si].first);
            if(newdiff < diff && mp.size() == m){
                asi = si;
                aei = ei;
                diff = newdiff;
            }
            

        }

        return {v[asi].first, v[aei].first};
    }
};