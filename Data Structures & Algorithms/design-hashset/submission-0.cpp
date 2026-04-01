class MyHashSet {
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        mySet[key]=1;
    }
    
    void remove(int key) {
        mySet[key]=0;
    }
    
    bool contains(int key) {
        return mySet[key];
    }
private:
    int mySet[(int)(1e6+1)]={0};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */