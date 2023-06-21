class LRUCache {
    private:
        struct Node{
            int key, value ;
            Node* prev ;
            Node* next ;
            Node(int k, int v) : key(k), value(v), prev(nullptr),next(nullptr){}
        };
        unordered_map<int,Node*>cache ;
        int capacity ;
        Node* head ;
        Node* tail ;
        void addToEnd(Node* node){
            node->next = tail ;
            node->prev = tail->prev ;
            tail->prev->next = node ;
            tail->prev = node ;
        }
        void deleteNode(Node* node){
            node->prev->next = node->next ;
            node->next->prev = node->prev ;
        }
        void moveNode(Node* node){
            deleteNode(node) ;
            addToEnd(node) ;
        }
        void ClearCache_Node(){
            Node* node = head->next ;
            cache.erase(node->key) ;
            deleteNode(node) ;
            delete node ;
        }
 
public:
    LRUCache(int capacity) : capacity(capacity){
        head = new Node(-1,-1) ;
        tail = new Node(-1,-1) ;
        head->next = tail ;
        tail->prev = head ;
    }

    int get(int key) {
        if (cache.find(key)!=cache.end()){
            moveNode(cache[key]) ;
            return cache[key]->value ;
        }
        return -1 ;
    }
    
    void put(int key, int value) {
        if (cache.find(key)!=cache.end()){
            cache[key]->value = value ;
            moveNode(cache[key]) ;
        }
        else{
            Node* node = new Node(key,value) ;
            addToEnd(node) ;
            cache[key] = node ;
            if (cache.size()>capacity)
                ClearCache_Node() ;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */