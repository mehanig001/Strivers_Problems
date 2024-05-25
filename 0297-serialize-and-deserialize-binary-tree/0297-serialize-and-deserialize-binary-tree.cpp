/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec{
    private:
    
    string conv(int n){
        if(n == 0)return "0,";
        string x = "";
        bool neg = 0;
        if(n<0){
            neg = 1;
        }
        n = abs(n);

        x+=',';
        while(n != 0){
            x += (n%10 + '0');
            n/=10;
        }
        if(neg)x+='-';
        reverse(x.begin(),x.end());

        return x;

    }

    int deconv(string x){
        int ans = 0;
        bool neg = 0;
        int i = 0;
        if(x[0] == '-'){neg = 1;i++;}
        while(x[i] != ','){
            ans = ans*10 + (x[i]-'0');
            i++;
        }

        if(neg)ans = -1*ans;
        return ans;
    }

    string getNext(string data, int &i){
        string x = "";
        while(data[i] != ','){
            x += data[i];
            i++;
        }
        x += ',';i++;
        return x;
    }

    public:
   
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)return "#,";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* tp = q.front();
                q.pop();
                if(tp != NULL)
                                     //-13 is not a single character so we can use ','
                s += conv(tp->val);
                else
                s += "#,";
                if(tp != NULL){
                    q.push(tp->left);
                    q.push(tp->right);
                }
            }
        }
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;

        string x = getNext(data,i);

        if(x == "#,")return NULL;
        TreeNode* root = new TreeNode(deconv(x));
        string l = "";
        string r = "";

        queue<TreeNode *> q;
        q.push(root);

        int k = i;  //for traversal of data
        

        while(!q.empty()){

            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* tp = q.front();
                q.pop();
                string x = getNext(data,k);
               
                if(x == "#,"){
                    tp->left = NULL;
                }
                else{
                    int d = deconv(x);
                    tp->left = new TreeNode(d);
                    q.push(tp->left);
                }
           
                x = getNext(data,k);

                if(x == "#,"){
                    tp->right = NULL;
                }
                else{
                    int d = deconv(x);
                    tp->right = new TreeNode(d);
                    q.push(tp->right);
                }
            }
        }

        return root;
    }
    
    
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));