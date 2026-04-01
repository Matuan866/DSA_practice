class MyHashMap {
public:
    MyHashMap() {
        numBuckets=10000;
        Buckets.resize(numBuckets);
    }
    
    void put(int key, int value) {
        int index=hashFunc(key);
        for(auto& Pair:Buckets[index]){
            if(Pair.first==key) {
                Pair.second=value;
                return ;}
        }
        Buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index=hashFunc(key);
        for(const auto& Pair:Buckets[index]){
            if(Pair.first==key) return Pair.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index=hashFunc(key);
        for(auto it=Buckets[index].begin();it!=Buckets[index].end();++it){
            if(it->first==key) Buckets[index].erase(it);
            return ;
        }
    }
private:
    int numBuckets;
    vector<std::list<pair<int, int>>> Buckets;
    int hashFunc(int key) {return key%numBuckets;}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */