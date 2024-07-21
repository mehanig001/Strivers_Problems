struct Node{
    int key, value;
    Node *prev, *next;
    int count;

    Node(int k, int v){
        key = k;
        value = v;
        prev = next = NULL;
        count = 1;
    }
};

struct List{
    int size;
    Node *head, *tail;

    List(){
        head = tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node){
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void deleteNode(Node *node){
        Node *prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
        size--;
    }


};

class LFUCache {
    map<int, List*> freqList;
    map<int, Node*> keyNode; //key, Node*
    int cap, minFreq, currSize;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = currSize =  0;
    }

    void updateFreqList(Node *node){
        keyNode.erase(node->key);
        freqList[node->count]->deleteNode(node);
        if(node->count == minFreq && freqList[node->count]->size == 0){
            minFreq++;
        }
        List *nxtHigherFreqList = new List();
        if(freqList.find(node->count+1) != freqList.end()){
            nxtHigherFreqList = freqList[node->count+1];
        }
        node->count += 1;
        nxtHigherFreqList->addFront(node);
        freqList[node->count] = nxtHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cap == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else{
            if(currSize == cap){
                List *list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }

            currSize++;
            minFreq = 1;
            List *listFreq = new List();

            if(freqList.find(minFreq) != freqList.end()){
                listFreq = freqList[minFreq];
            }



            Node* newnode = new Node(key, value);
            listFreq->addFront(newnode);
            keyNode[key] = newnode;
            freqList[minFreq] = listFreq;
        }

        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */