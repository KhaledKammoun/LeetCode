class LRUCache {
    private:
        struct Node{
            int key, value ;
            Node* next ;
            Node* prev ;
            Node(int k, int v) :key(k), value(v), prev(nullptr), next(nullptr){}
        };
        
        unordered_map<int,Node*> m ;
        
        int capacity ;
        Node* head ;
        Node* tail ;
        void addToFront(Node* node){
            node->next = head->next ;
            node->prev = head ;
            head->next->prev = node ;
            head->next = node ;
        }
        void deleteNode(Node* node){
            node->next->prev = node->prev ;
            node->prev->next = node->next ;
        }
        void moveToFront(Node* node){
            deleteNode(node) ;
            addToFront(node) ;
        }
        void clearCache_Map(){
            Node* node = tail->prev ;
            m.erase(node->key) ;
            deleteNode(node) ;
            delete node ;
        }
    
public:
    LRUCache(int capacity) : capacity(capacity){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail ;
        tail->prev = head ;
    }

    int get(int key) {
        if (m.find(key) != m.end()){
            moveToFront(m[key]) ;
            return m[key]->value ;
        }
        else 
            return -1 ;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()){
            m[key]->value = value ;
            moveToFront(m[key]) ;
        }
        else{
            Node* node = new Node(key,value) ;
            addToFront(node) ;
            m[key]=node ;
            if (capacity<m.size()){
                clearCache_Map() ;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */