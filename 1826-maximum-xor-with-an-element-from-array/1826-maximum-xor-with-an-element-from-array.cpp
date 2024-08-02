string bin(int n){
    string ans = "";
    while(n){
        ans += '0' + (n&1);
        n = n>>1;
    }
    while(ans.size() < 32){
        ans.push_back('0');
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int decimal(string s){
    int ans = 0;
    for(int i = 0; i < 32; i++){
        if(s[i] == '1'){
            ans += (1 << (31-i));
        }
    }
    return ans;
}



struct Node{
    Node* arr[2];

    bool contains(char &ch){
        return arr[ch - '0'] != NULL;
    }
    Node* add(char &ch, Node *node){
        arr[ch - '0'] = node;
        return node;
    }

    Node *next(char &ch){
        return arr[ch - '0'];
    }

	bool isEmpty(){
		return (arr[0] == NULL && arr[1] == NULL);
	}

};

class Trie{

  private:
    Node *root;

  public:
    Trie(){
        root = new Node();
    }


    void insert(string str){
        Node *node = root;
        for(int i = 0; i < str.size(); i++){
            if(!node->contains(str[i])){
                node = node->add(str[i], new Node());
            }
            else node = node->next(str[i]);
        }
    }

    int solve(string x){
        string ans = "";
		if(root->isEmpty())return -1;
        Node *node = root;

        for(int i = 0; i < x.size(); i++){
            char flip = '1' - (x[i]) + '0';
            if(node->contains(flip)){
                ans += "1";
                node = node->next(flip);
            }
            else{
                ans += "0";
                node = node->next(x[i]);
            }
        }
		// cout<<ans<<endl;

        return decimal(ans);
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();

	vector<int> ans(m,-1);
	Trie *t = new  Trie();


	vector<int> v = nums;
	sort(v.begin(), v.end());
	
	vector<pair<pair<int,int>,int>> vp(m);
	for(int i = 0; i < m; i++){
		vp[i].first.first = queries[i][1];
		vp[i].first.second = queries[i][0];
		vp[i].second = i;
	}
	sort(vp.begin(), vp.end());


	int k = 0; //inserting idx of tries
	for(int i = 0; i < m; i++){

		int xi = vp[i].first.second;
		int ai = vp[i].first.first;
		int idx = vp[i].second;
		

		// cout<<xi<<" "<<ai<<" "<<idx<<" "<<k<<endl;


		while(k < n && v[k] <= ai){
			t->insert(bin(v[k]));
			k++;
		}

		ans[idx] = t->solve(bin(xi));
	}

	return ans;
    }
};