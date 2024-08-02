string bin(int n){
    string ans = "";
    while(n){
        ans += char('0' + (n&1));
        n = n>>1;
    }
    int x = ans.size();
    for(int i = x+1; i <= 32; i++){
        ans += '0';
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int binToInt(string str){
    int ans = 0;
    int pow = 0;
    for(int i = 31; i >= 0; i--){
        pow = 1<<(31-i);
        if(str[i] == '1')ans += pow;
    }
    return ans;
}

struct Node{
    Node* link[2];
    
    
    bool contains(char ch){
      
        return link[ch-'0'] != NULL;
    }

    Node* next(char ch){
        return link[ch-'0'];
    }
    Node* add(char ch, Node *node){
        link[ch-'0'] = node;
        return node;
    }
    bool isEmpty(){
        return link[0] == NULL && link[1] == NULL;
    }

};

class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int n){
            string str = bin(n);
            Node *temp = root;
            for(auto ch : str){
                if(temp->contains(ch)){
                    temp = temp->next(ch);
                }
                else{
                    temp = temp->add(ch, new Node());
                }
            }
        }

        int findMaxXor(int x){
            int ans = 0;
            string str = bin(x);
            if(root->isEmpty())return -1;
            Node *temp = root;

            string newstr = "";
            for(auto ch : str){
                char ulta = '0' + ('1'- ch);
                // cout<<ulta<<endl;
                if(temp->contains(ulta)){
                    temp = temp->next(ulta);
                    newstr += '1';
                }
                else{
                    temp = temp->next(ch);
                    newstr += '0';
                }
            }

            return binToInt(newstr);

        }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int> nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int,pair<int,int>>> v(queries.size());
        for(int i = 0; i < queries.size(); i++){
            v[i].first = queries[i][1];
            v[i].second.first = queries[i][0];
            v[i].second.second = i;

        }
        sort(v.begin(), v.end());

        int k = 0;
        Trie *tr = new Trie();
        vector<int> ans(queries.size());

        
        // cout<<binToInt(bin(717))<<endl;

        for(int i = 0; i < v.size(); i++){
            auto pr = v[i];
            while(k < nums.size() && nums[k] <= pr.first){
                tr->insert(nums[k]);
                k++;
            }
            ans[pr.second.second] = tr->findMaxXor(pr.second.first);

        }
        return ans;
    }
};