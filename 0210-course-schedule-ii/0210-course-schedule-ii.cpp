class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++){
            for(int j = 0; j < prerequisites[0].size(); j++){
                adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
        }

        vector<int> indegree(numCourses);
        for(int i = 0; i < numCourses; i++){
            for(auto val : adj[i]){
                indegree[val]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            ans.push_back(tp);
            for(auto val : adj[tp]){
                indegree[val]--;
                if(indegree[val] == 0){
                    q.push(val);
                }
            }
        }

        if(ans.size() != numCourses)ans.clear();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};