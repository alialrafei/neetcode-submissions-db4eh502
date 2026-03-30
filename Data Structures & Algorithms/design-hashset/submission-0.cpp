class MyHashSet {
public:
    vector<int> table;
    int const MAX_NUM = (int)1e6+7;
    // int toInt(char c){
    //     if(c>='a' && c<= 'z')
    //         return c - 'a';
    //     return c-'A';
    // }
    // int hash(string s){
    //     int h = 0;
    //     int P = 31;
    //     for(char c:s){
    //         h = h * p + toInt(c); 
    //     }
    //     h ^= (h>>16);
    //     return h;
    // }
    MyHashSet() {
        table = vector<int>(MAX_NUM,0);
    }
    
    void add(int key) {
        table[key]++;
    }
    
    void remove(int key) {
        table[key] = 0;
    }
    
    bool contains(int key) {
        return table[key]>0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */