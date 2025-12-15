
class MyHashMap {
    vector<list<pair<int,int>>>bucket;
    size_t bucket_size = 1e4;
public:
    MyHashMap() {
        bucket.resize(bucket_size);
    }
    
    void put(int key, int value) {
        int bi = key%bucket_size;
        auto &list = bucket[key % bucket_size];

        auto it = bucket[bi].begin();
        while(it!=bucket[bi].end()){
            if(it->first==key){
                it->second = value;
                break;
            }
            it++;
        }
        list.emplace_back(key,value);
    }
    
    int get(int key) {
        int bi = key%bucket_size;
        auto &list = bucket[key % bucket_size];

        if(list.empty()) return -1;

        auto it = bucket[bi].begin();
        while(it!=bucket[bi].end()){
            if(it->first==key){
                return it->second;
            }
            it++;
        }
        return -1;
    }
    
    void remove(int key) {
        int bi = key%bucket_size;
        auto &list = bucket[key % bucket_size];
        // list.remove_if([key](auto n) { return n.first == key; });
        list.remove_if([key](const pair<int,int> &p){
            return p.first==key;
        });
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */