//LEETCODE
//LRU CACHE USING DOUBLE LINKED LIST

class Node {
    public:
    Node* prev =NULL;
    int key;
    int value;
    Node* next=NULL;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
    }
};

class LRUCache {
public:
    int cap;
    int size = 0;
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    unordered_map<int,Node*>mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    Node* insertAtHead(int key, int value) {
        Node* temp = new Node(key,value);
        Node *temp1 = head->next;
        temp1->prev = temp;
        temp->next = temp1;
        head->next = temp;
        temp->prev  = head;
     
        return temp;
    }
    
    void deleteAnyNode(Node* temp) {
        Node * temp1 = temp->prev;
        Node* temp2 = temp->next;
        temp1->next = temp2;
        temp2->prev = temp1;

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) {
            return -1;
        }   
        Node* temp = mp[key];
       int  value = temp->value;
        deleteAnyNode(temp);
       mp[key] =  insertAtHead(key,value);
        return value;
    }
    
    void put(int key, int value) {
        Node* temp;
        if(mp.find(key)!=mp.end()) {
            temp = mp[key];
            deleteAnyNode(temp);
            mp[key] = insertAtHead(key,value);
        }
        else {
            if(size<cap) {
                mp[key] = insertAtHead(key,value);
                size++;
            }
            else {
               int key1 = tail->prev->key;
                deleteAnyNode(tail->prev);
                mp.erase(key1);
                mp[key] = insertAtHead(key,value);
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
