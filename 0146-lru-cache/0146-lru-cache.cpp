class Node{
    //friend class LRUCache;
//private: 


   
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val){
        this->key = key;
        this->val=val;
        next=NULL;
        prev = NULL;
    }



};

class LRUCache {
private:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);;
    unordered_map<int, Node*> mp;
    int capacity=0;

    void removeNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        node->next=NULL;
        node->prev = NULL;
        return;
    }

    void insertAfterHead(Node* node){
        Node* curNext = head->next;

        head->next = node;
        node->prev = head;
        node->next = curNext;
        curNext -> prev = node;
        return;
    }


public:
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev = head;
        mp.clear();
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node = mp[key];

        removeNode(node);
        insertAfterHead(node);
        return node->val;      
    }
    
    void put(int key, int value) {
        if(capacity==0){
            return;
        }
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val=value;
            removeNode(node);
            insertAfterHead(node);
            return;
        }

        if(mp.size()==capacity){
            Node* lruNode = tail->prev;
            mp.erase(lruNode->key);
            removeNode(lruNode);
        }

        Node* newNode = new Node(key, value);
        insertAfterHead(newNode);
        mp[key]= newNode;
        return;


        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */