/* LRU using unordered_hash map and doubly linked list ( stl list) */
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LRUCache
{

public:
    int capacity;
    list<int> List;
    unordered_map<int, pair<list<int>::iterator, int>> hash;
    LRUCache(int cap)
    {

        capacity = cap;
    }

    int get(int key)
    {
        list<int>::iterator it;
        // check if key not present
        if (hash.find(key) == hash.end())
            return -1;
        // if present
        // get elemnt reference and erase
        int value = hash[key].second;

        List.erase(hash[key].first);
        hash.erase(key);
        List.push_front(key);
        it = List.begin();
        hash[key] = {it, value};

        return value;
    }

    void put(int key, int value)
    {

        list<int>::iterator it;
        // not present
        if (hash.find(key) == hash.end())
        {

            // put it
            // if size greater than capacity
            if (List.size() >= capacity)
            {
                hash.erase(List.back());
                List.pop_back();
            }
        }
        else // presrnt
            List.erase(hash[key].first);

        List.push_front(key);
        it = List.begin();
        hash[key] = {it, value};
    }
};

/**
Your LRUCache object will be instantiated and called as such:*/

int main()
{
    // capacity of cache
    int capacity = 2;
    LRUCache *obj = new LRUCache(capacity);
    obj->put(1, 1); // cache is {1=1}
    obj->put(2, 2); // cache is {1=1, 2=2}
    cout<<obj->get(1)<<endl;    // return 1
    obj->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout<<obj->get(2)<<endl;    // returns -1 (not found)
    obj->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout<<obj->get(1)<<endl;    // return -1 (not found)
    cout<<obj->get(3)<<endl;  // return 3
    cout<<obj->get(4)<<endl;    // return 4
    return 0;
}
