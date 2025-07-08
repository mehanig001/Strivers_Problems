struct Node{
    int key, value;
    Node *prev, *next;
    Node(int k, int v){
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
    Node(){}
};
class LRUCache {
    Node *head;
    Node *tail;
    unordered_map<int, Node*> mp;
    int sz;
    int currsz = 0;

    void del(Node *node){
        if(head == node){
            if(tail == node){
                head = NULL;
                tail = NULL;
            }
            else{
                head = head->next;
                head->prev = NULL;
            }
        }
        else{
            if(tail == node){
                tail = tail->prev;
                tail->next = NULL;
            }
            else{
                node->next->prev = node->prev;
                node->prev->next = node->next;
            }
        }
        currsz--;
        mp.erase(node->key);
    }
    void add(int k, int v){
        Node* newnode = new Node(k, v);
        mp[k] = newnode;
        if(!tail){
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        currsz++;
    }
    void deleteLast(){
        if(head == tail){
            head = NULL;
            tail = NULL;
        }
        else{
            tail = tail->prev;
            mp.erase(tail->next->key);
            tail->next = NULL;
        }
        currsz--;
    }
public:
    LRUCache(int capacity) {
        sz = capacity;
        currsz = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(mp[key] != NULL){
            Node* node = mp[key];
            int value = node->value;
            del(node);
            add(key, value);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp[key]){
            Node* node = mp[key];
            del(node);
        }
        add(key, value);

        if(currsz > sz)deleteLast();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */