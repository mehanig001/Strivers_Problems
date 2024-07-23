class Solution {

public:
    int repeatedStringMatch(string a, string b) {
        int rep = 0;
        string x = a;
        while(a.find(b) == string::npos){
            a += x;
            rep++;

            if(a.size() > 1e4)return -1;
        }

        return rep+1;
    }
};