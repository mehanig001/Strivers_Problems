class Solution {
private:
    bool isPair(char a, char b){
        if(a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']'){
            return true;
        }
        return false;
    }
public:
    bool isValid(string s) {
        vector<int> opening;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                opening.push_back(s[i]);
            }
            else{
                if(opening.empty()){
                    return false;
                }
                else{
                    char recent = opening.back();
                    if(!isPair(recent,s[i])){
                        return false;
                    }
                    opening.pop_back();
                }
            }
        }
        return opening.empty();
    }
};