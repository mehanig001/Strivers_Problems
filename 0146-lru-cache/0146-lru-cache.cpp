struct Node{

    pair<int,int> pr;
    Node *prev, *next;

    Node(int key, int value){
        pr.first = key;
        pr.second = value;
        prev = next = NULL;
    }

};



class LRUCache {
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
        
    }
    void deleteNode(Node *node){
        Node *delprev = node->prev;
        node->next->prev = delprev;
        delprev->next = node->next;
        // delete(node);
    }
    int get(int key) {
        if(head->next == tail)return -1;
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* node = mp[key];
        int val = node->pr.second;
        deleteNode(node);
        addNode(node);
        mp[key] = head->next;

        return val;

    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            mp.erase(key);
            deleteNode(existing);
            
        }

        if(mp.size() == cap){
            mp.erase((tail->prev)->pr.first);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */