class MyHashSet {
public:
    MyHashSet() {
        numBuckets=10000;
        Buckets.resize(numBuckets);
    }
    
    void add(int key) {
        int index=hashFunc(key);
        std::list<int>::iterator it=find(Buckets[index].begin(), Buckets[index].end(), key);
        if(it==Buckets[index].end()) Buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index=hashFunc(key);
        Buckets[index].remove(key);
    }
    
    bool contains(int key) {
        int index=hashFunc(key);
        std::list<int>::iterator it=find(Buckets[index].begin(), Buckets[index].end(), key);
        return it!=Buckets[index].end();
    }
private:
    int numBuckets;
    vector<std::list<int>> Buckets;
    int hashFunc(int key) {return key%numBuckets;}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */