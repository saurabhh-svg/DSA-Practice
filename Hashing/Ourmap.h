#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class Ourmap
{
    MapNode<V> **buckets;
    int count;
    int numBucket;

public:
    Ourmap()
    {
        count = 0;
        numBucket = 5;
        buckets = new MapNode<V> *[numBucket];
        for (int i = 0; i < numBucket; i++)
            buckets[i] = NULL;
    }

    ~Ourmap()
    {
        for (int i = 0; i < numBucket; i++)
            delete buckets[i];

        delete[] buckets;
    }

    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        int hashcode = 0, currCoeff = 1;

        for (int i = key.size() - 1; i >= 0; i--)
        {
            hashcode += (key[i] * currCoeff) % numBucket;
            currCoeff = (currCoeff * 37) % numBucket;
        }
        return hashcode % numBucket;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBucket];
        for (int i = 0; i < 2 * numBucket; i++)
            buckets[i] = NULL;

        int oldBucketcount = numBucket;
        numBucket *= 2;
        count = 0;

        for (int i = 0; i < oldBucketcount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head)
            {
                string key = head->key;
                V val = head->value;
                insert(key, val);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketcount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

    // bucket is an array of indexes
    // at each index we have linkedlist attached to it

    void insert(string key, V val)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> **head = buckets[bucketIndex];
        while (!head)
        {
            if (head->val == key) // if key already exists
            {
                head->value = val;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> **node = new MapNode<V>(key, val);
        node->next = head;
        buckets[bucketIndex] = node;
        count++; // increasing size of map

        double loadfactor = (1.0 * count) / numBucket;
        if (loadfactor > 0.7)
            rehash();
    }
    V getvalue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> **head = buckets[bucketIndex];
        while (!head)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> **head = buckets[bucketIndex];
        MapNode<V> **prev = NULL;
        while (!head)
        {
            if (head->key == key)
            {
                if (!prev)
                    buckets[bucketIndex] = head->next;
                else
                    prev->next = head->next;
                V val = head->value;
                head->next = NULL;
                delete head;
                count--;
                return val;
            }
            prev = head;
            head = head->next;
        }
    }
};