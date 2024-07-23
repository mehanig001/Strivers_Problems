class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int rep = b.size() / a.size();
        int count = 1;
        string x = a;
        while(count <= rep+2){
            if((a).find(b) != string::npos){
                return count;
            }
            else count++;

            a = a+x;
        }

        return -1;
    }
};