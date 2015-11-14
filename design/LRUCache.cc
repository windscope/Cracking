#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

class LRUCache{
private:
    
    list<int> l;
    unordered_map<int, int> memory;
    unordered_map<int, list<int>::iterator> m; 
    int maxSize;
    
    void evict() {
        memory.erase(l.front());
        l.pop_front();
    }
    
    void update(int key) {
        if (m.find(key) != m.end()) {
            l.erase(m[key]);
        }
        l.push_back(key);
        list<int>::iterator tail = l.end();
        tail--;
        m[key] = tail;
    }
    
public:
    LRUCache(int capacity) : maxSize(capacity), m(), l() {}
    
    int get(int key) {
        if (memory.find(key) == memory.end()) return -1;
        update(key);
        return memory[key];
    }
    
    void set(int key, int value) {
        if (memory.find(key) != memory.end()) {
            update(key);
            memory[key] = value;
	    cout << memory[key] << endl;
        } else {
	    if (maxSize == m.size()) {
                evict();
            }
	    update(key);
            memory[key] = value;   	
	}
    }
};


int main() {
    LRUCache cache(1);
    cache.set(2, 1);
    cache.set(1,2);
    cout << cache.get(1) << endl;
    return 0;
}