class MyHashSet {
public:
    vector<list<int>> hashSet;
    static const int base = 769;
    inline static int hash(int key){
        return key % base;
    }

    /** Initialize your data structure here. */
    MyHashSet() : hashSet(base) {

    }

    void add(int key) {
        int hashAddr = hash(key);
        for (auto it = hashSet[hashAddr].begin(); it != hashSet[hashAddr].end(); it++) {
            if((*it) == key) return;
        }
        hashSet[hashAddr].push_back(key);
    }

    void remove(int key) {
        int hashAddr = hash(key);
        for (auto it = hashSet[hashAddr].begin(); it != hashSet[hashAddr].end(); it++) {
            if ((*it) == key) {
                hashSet[hashAddr].erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashAddr = hash(key);
        for (auto it = hashSet[hashAddr].begin(); it != hashSet[hashAddr].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }
};
