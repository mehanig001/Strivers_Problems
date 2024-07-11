class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

    

        stack<int> left;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                st.push('(');
                left.push(i);
            }
            else if(ch == ')'){
                st.pop();
                reverse(s.begin() + (left.top() + 1),s.begin() + i);   
                left.pop();

            }
        }
        string ans = "";
        for(auto &ch : s){
            if(ch != '(' && ch != ')'){
                ans += ch;
            }
        }
        return ans;
    }
};