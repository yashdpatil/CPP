#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
class hashing
{
    vector<list<int>> hash;
    int buckets;

public:
    hashing(int size)
    {
        buckets = size;
        hash.resize(size);
    }
    // division method

    int hashvalue(int key)
    {
        return key % buckets;
    }

    void addKeys(int key)
    {
        int index = hashvalue(key);
        hash[index].push_back(key);
    }

    list<int>::iterator searchKey(int key)
    {
        int index = hashvalue(key);
        return find(hash[index].begin(), hash[index].end(), key);
    }

    void deletekey(int key)
    {
        int index = hashvalue(key);
        if (searchKey(key) != hash[index].end())
        {
            hash[index].erase(searchKey(key));
        }
        cout << "key deleted";
    }

    void display()
    {
        for (int i = 0; i < buckets; i++)
        {
            cout << i << " -> ";
            for (int x : hash[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main()
{

    hashing h(10);
    h.addKeys(30);
    h.addKeys(40);
    h.addKeys(50);
    h.addKeys(60);
    h.addKeys(20);
    h.addKeys(20);

    h.deletekey(20);
    h.deletekey(60);
    h.display();
    return 0;
}