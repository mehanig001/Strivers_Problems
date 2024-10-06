class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int sum = skill[0] + skill[n-1];
        ans += (skill[0] * skill[n-1]);
        int i = 1, j = n-2;
        while(i < j){
            if(skill[i] + skill[j] == sum){
                ans += (skill[i] * skill[j]);
                i++;
                j--;
            }
            else return -1;
        }
        return ans;
    }
};