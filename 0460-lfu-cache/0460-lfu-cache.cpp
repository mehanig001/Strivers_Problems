struct Node{
    int key, value;
    Node *prev, *next;
    int count;
    Node(int k, int v){
        key = k;
        value = v;
        count = 1;
    }
};

struct List{
    Node* head;
    Node* tail;
    int sz;

    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }


    void add(Node *newnode){
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        sz++;
    }

    void del(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        sz--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqList;
    int cap, minFreq, currSize;

    void delLFU(){
        List *list = freqList[minFreq];
        keyNode.erase(list->tail->prev->key);
        list->del(list->tail->prev);
    }

    void add(int key, int value){
        minFreq = 1;
        List *listFreq = new List();

        if(freqList.find(minFreq) != freqList.end()){
            listFreq = freqList[minFreq];
        }
        Node* newnode = new Node(key, value);
        listFreq->add(newnode);
        keyNode[key] = newnode;
        freqList[minFreq] = listFreq;
    }

    void update(Node* node, int val){
        keyNode.erase(node->key);
        freqList[node->count]->del(node);
        if(node->count == minFreq && freqList[node->count]->sz == 0){
            minFreq++;
        }
        List *nxtHigherFreqList = new List();
        if(freqList.find(node->count+1) != freqList.end()){
            nxtHigherFreqList = freqList[node->count+1];
        }
        node->count += 1;
        nxtHigherFreqList->add(node);
        freqList[node->count] = nxtHigherFreqList;
        node->value = val;
        keyNode[node->key] = node;
    }
public:
    LFUCache(int capacity) {
        cap = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyNode[key]){
            //freqBadhaoAurAgeLao
            update(keyNode[key], keyNode[key]->value);
            return keyNode[key]->value;
            
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(keyNode[key]){
            //freqBadhaoAurAgeLao
            update(keyNode[key], value);
            return;
        }
        if(currSize == cap){
            delLFU();
            currSize--;
        }
        add(key, value);
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */