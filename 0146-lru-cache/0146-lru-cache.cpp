class LRUCache {
public:
    class Node{
    public:
        int val;
        int idx;
        Node* next;
        Node* prev;
        Node(int val, int key){
            this->val=val;
            this->idx=key;
            next=prev=NULL;
        }
    };
    int size;
    Node* head=NULL; Node* tail=NULL;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        size=capacity; 
        Node* dummy=new Node(-1, -1);
        head=tail=dummy;
    }
    
    int get(int key) {
        //if key already exist in map
        if(mp.count(key)){
            Node* temp=mp[key];
            if(temp != tail){
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
                tail->next=NULL;
            }
            return mp[key]->val;
        }
        //otherwise return -1
        return -1;
    }
    
    void put(int key, int value) {
        //agar key already present hai
        if(mp.count(key)){
            Node* temp=mp[key];
            temp->val=value;
            if(temp != tail){
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
                tail->next=NULL;
            }  
            return;
        }
        //agar key present nahi hai
        //case 1- agar size full hai datastructure ka
        if(size<=0){
            Node* temp=head->next;
            head->next=temp->next;
            if(temp->next)  temp->next->prev=temp->prev;
            mp.erase(temp->idx);
            if(temp==tail)  tail=head;
            delete temp;
            size++;
        }
        //naya node insert kro
        Node* newnode=new Node(value, key);
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
        mp[key]=newnode;
        size--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */