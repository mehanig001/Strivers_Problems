class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<int> visited(n+1,0);

        for(int i = 0; i < n; i++){
            visited[A[i]] += 1;
            visited[B[i]] += 1;

            int ct = 0;
            if(A[i] == B[i])ct = 1;
            else{
                if(visited[A[i]] == 2)ct++;
                if(visited[B[i]] == 2)ct++;
            }

            int prev = (i > 0) ? C[i-1] : 0;
            C[i] = prev + ct;
        }
        return C;
    }
};