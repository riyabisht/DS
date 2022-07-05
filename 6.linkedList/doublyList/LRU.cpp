#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;
class LRU
{
private:
    list<int> dp; // doubly linked list
    unordered_map<int, list<int>::iterator> hash;

public:
    int capacity;
    LRU(int);
    ~LRU();
    int get(int);
    void put(int);
};

LRU::LRU(int cap)
{
    capacity = cap;
}

int LRU ::get(int key)
{
    // get key 
    list<int>:: iterator it;
    it = find(dp.begin(), dp.end(), key);
    //if not present
    if(it==dp.end())
        return -1;
    //if present
    dp.erase(it);
    dp.push_front(key);
    return key;

}
void LRU::put(int n)
{
    list<int>:: iterator it;
    it = find(dp.begin(), dp.end(), n);
    // not present in cache
    //cout<<dp.size();
    if ( it== dp.end())
        // check cache size
        if (dp.size() > capacity)
            dp.pop_back();

    //present
    else
        dp.erase(it);

    dp.push_front(n); 
}
    LRU::~LRU()
    {
    }

    int main()
    {

        vector<int> arr({5, 4, 1, 3});
        LRU *obj = new LRU(4);
        obj->put(5);

        return 0;
    }