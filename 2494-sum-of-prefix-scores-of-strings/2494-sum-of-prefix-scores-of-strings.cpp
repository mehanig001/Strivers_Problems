class Node{
  public:
    Node* arr[26];
    int pre = 0;
   
    
    bool consist(char &ch){
        return arr[ch-'a'] != NULL;
    }

    void add(char &ch, Node *newnode){
        arr[ch-'a'] = newnode;
    }

    Node* next(char &ch){
        return arr[ch-'a'];
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insertWord(string str){
        Node* temp = root;
        for(auto &ch : str){
            if(temp->consist(ch)){
                temp = temp->next(ch);
                temp->pre++;
            }
            else{
                Node* newnode = new Node();
                temp->add(ch, newnode);
                temp = temp->next(ch);
                temp->pre = 1;
            }

          
        }
    }


    int preCount(string &word){
        int ans = 0;
        Node* temp = root;
        for(auto &ch : word){
            temp = temp->next(ch);
            ans += temp->pre;
        }
        return ans;
    }  
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* t = new Trie();
        for(auto str : words){
            t->insertWord(str);
        }

        vector<int> ans;
        for(auto str : words){
            ans.push_back(t->preCount(str));
        }
        return ans;
    }
};