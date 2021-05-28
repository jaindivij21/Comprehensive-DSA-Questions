// Hashing/HashMap Class Implementation :: Chaining Method for Collision
/*
 *  Separate Chaining Method, And for simplicity sake, the key can only be string, since otherwise we'll have to make multiple hash functions
 */

#include<bits/stdc++.h>

using namespace std;

// class for the node of linked list
template<typename T>
class node {
public:
    string key;
    T data;
    node<T> *next;

    node(string k, T d) {
        key = k;
        data = d;
    }

    ~node() {
        // recursive destructor calls : destructor calling the destructor of next node
        if (next != nullptr) {
            delete next;
        }
    }
};

// main hash table function
template<typename T>
class HashTable {
    int currentSize;    // Current Array Size
    int tableSize;  // Max Array Size
    node<T> **buckets;  // Array i.e. basically your hash table

    // REHASH FUNCTION
    void rehash() {
        // store the original array's information in a new array
        node<T> **oldBuckets = buckets;
        int oldTableSize = tableSize;
        tableSize = tableSize * 2;

        // update buckets
        currentSize = 0;
        buckets = new node<T> *[tableSize];   // assigned new space
        // initialize all of them to nullptr
        for (int i = 0; i < tableSize; i++) {
            buckets[i] = nullptr;
        }

        // now read data from oldbuckets hash table to buckets
        for (int i = 0; i < oldTableSize; i++) {
            node<T> *temp = oldBuckets[i];
            while (temp != nullptr) {
                insert(temp->key, temp->data);  // this statement runs on buckets array only
                temp = temp->next;
            }
            // after copying delete old table row or linked list
            delete oldBuckets[i];   // for this to work destructor that deletes all the nodes recursively, thus need to be defined in the node class OR use a loop to delete all the nodes (difficult)
        }
        // after this all the rows or LLs will be deleted but the old buckets array remains, so delete that
        delete[]oldBuckets;
    }

    // hash Function :: inputs the key and gives an index to the buckets array
    // private method
    int hashFn(string key) {
        // hash function can be random : in this case it multiplies string's last char's (l) ASCII with 37, then l-1th char's ASCII with 37*37 and so on!
        int len = key.length();
        int ans = 0;
        int p = 37; // multiplication factor
        for (int i = len - 1; i >= 0; i--) {
            ans += key[i] * p;
            p *= 37;

            // to not overflow the value : since these can be very large numbers
            p %= tableSize;
            ans %= tableSize;
        }
        return ans;
    }

public:
    // constructor :: gives default table size as 7
    HashTable(int ts = 7) {
        // give sizes
        currentSize = 0;
        tableSize = ts;
        // initialize buckets
        buckets = new node<T> *[tableSize]; // make the bucket of size table size where each index holds addresses to nodes

        // make all the bucket addresses as null/0
        for (int i = 0; i < tableSize; i++) {
            buckets[i] = nullptr;
        }
    }


    // insert function
    void insert(string key, T data) {
        // get the buckets array index using a hash function
        int index = hashFn(key);
        // create a new node and add it to the front of the chaining on the hash index
        node<T> *newNode = new node<T>(key, data);
        newNode->next = buckets[index];
        buckets[index] = newNode;
        currentSize++;
        // Insertion over

        // REHASHING
        float load_factor = (float) currentSize / tableSize;
        if (load_factor > 0.7) {
            cout << "Load Factor is " << load_factor << endl;
            rehash();   // private function
        }
    }

    // print it function :: to print the entire hash table
    void print() {
        // iterate over each bucket
        for (int i = 0; i < tableSize; i++) {
            // on each bucket there will be a linked list to be printed
            node<T> *tempNode = buckets[i];
            cout << "{ ";
             while (tempNode != nullptr) {
                cout << tempNode->key << ":";
                cout << tempNode->data << ", ";
                tempNode = tempNode->next;
            }
            cout << "NULL }" << endl;
        }
    }

    // search function :: a function that searches for the key, tells if it exists by returning its value or doesn't
    /*
     *  IMPORTANT: WHY DONT WE RETURN INT LIKE -1 FOR NOT FOUND AND 'VALUE' WHEN FOUND
     *      cuz 'T' data type can be string also. In that case, we'll get error since our return datatype is T buy we are returning int.
     *      Hence we keep our return datatype as T* or address of corresponding key's value, which we can later dereference as we did in operator overloading f(x)
     */

    // actual search function :: returns the address of the node's data, since we use pointer in the return type
    T *searchNode(string k) {
        // use the same hash function which is private to check the index of buckets array
        int index = hashFn(k);
        node<T> *nodeToBeFound = buckets[index];
        while (nodeToBeFound != nullptr) {
            if (nodeToBeFound->key == k) {
                // now nodeToBeFound points to the node we want to return
                return &(nodeToBeFound->data);
            }
            nodeToBeFound = nodeToBeFound->next;
        }
        // if the node required isn't found
        return nullptr;
    }

    // deletion
    // delete function :: inputs key and deletes the node that contains the key
    T *erase(string k) {
        // returns the address value of the node to be deleted
        int index = hashFn(k);
        node<T> *nodeToBeDel = buckets[index];
        // if the first node is the one to be deleted
        if (nodeToBeDel->key == k) {
            cout << "Node deleted :: Value : ";
            buckets[index] = nodeToBeDel->next;
            return &(nodeToBeDel->data);
        } else {
            // if the node to be deleted isn't the first node
            nodeToBeDel = nodeToBeDel->next;
            node<T> *prev = buckets[index]; // points to a node behind tobedeleted node
            while (nodeToBeDel != nullptr) {
                // if the node to be deleted is found
                if (nodeToBeDel->key == k) {
                    cout << "Node deleted :: Value : ";
                    prev->next = nodeToBeDel->next;
                    return &(nodeToBeDel->data);
                }
                // increment nodes
                nodeToBeDel = nodeToBeDel->next;
                prev = prev->next;
            }
            // if the node to be deleted isn't found
            cout << "Node to be deleted not found :: Error";
            return nullptr;
        }
    }

    // operator overloading :: using & before operator makes sure that a copy is returned rather exact object is returned (return by reference)
    T &operator[](string key) {
        // get the node's address that contains the key
        T *temp = searchNode(key);
        // if nullptr means key doesn't exist
        if (temp == nullptr) {
            // key doesn't exist, thus apply the insert functionality
            // insert a garbage value corresponding to the key **(usually its 0)**
            T garbage;
            insert(key, garbage);
            // now we return the de-referenced value of the value variable
            T *value = searchNode(key); // value stores the add of the key's node's data box
            return *(value);
            // BUT HOW DOES THIS INSERT THE REQD VALUE?
            //  ht["Divij"] = 69;
            // the LHS returns the de-referenced data value of key box (which is initially garbage == 0) and we set it to 69

        }
        // else the key exists, so return the key's data box's address into temp, hence we dereference it and return it
        return *temp;
    }
};

int main() {
    // test the function
    HashTable<int> ht(7);
    ht.insert("Mango", 100);
    ht.insert("Apple", 170);
    ht.insert("Guava", 140);
    ht.insert("Banana", 130);
    ht.print();
    cout<<ht["Chiku"]<<endl;
    ht["divij"] = 69;

    cout << *ht.erase("Banana") << endl;
    ht.erase("Apple");
    ht.print();
    return 0;
}