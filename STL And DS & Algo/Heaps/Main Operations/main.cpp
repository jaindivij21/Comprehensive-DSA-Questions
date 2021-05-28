// Heap - Main Operations
// Implementation using vectors/arrays

#include<iostream>
#include<vector>

using namespace std;

// heap class
template<typename T>
class heap {
    vector<T> v;
    bool whichHeap; // checks if the heap is min heap (0) or max heap (1)

    // comparator function
    bool compare(T a, T b) {
        if (whichHeap) {
            // max heap
            // return true when index element is bigger than the parent element
            return a > b;
        } else {
            // min heap
            // returns true when the index element is smaller than the parent element
            return b > a;
        }
    }

    // heapify recursive function
    void heapify(int index) {
        int mainIndex = index;
        int leftIndex = index * 2;
        int rightIndex = leftIndex + 1;

        if (leftIndex < v.size() && compare(v[leftIndex], v[index])) {
            // keep note in the compare function first comes the child then the parent
            // condition checks if the left index exists and then acc to the type of heap compares the parent and child
            mainIndex = leftIndex;  // if condition is true, in max heap the main index will now point to the left child means left child was bigger
        }
        if (rightIndex < v.size() && compare(v[rightIndex], v[mainIndex])) {
            // checks if the right index exists and if the right index is greater than max(left index, mainIndex) in case of max heap and vice versa
            // If true,
            mainIndex = rightIndex;
        }

        // if the index is already at its correct position then do nothing else swap and recursive call
        if (mainIndex != index) {
            // after the 2 if conditions, main Index will point to the max of index, left and right child in case of max heap and min in case of min heap
            swap(v[mainIndex], v[index]);

            // recursively call heapify on mainIndex which now points to the old index element and needs to be brought to its correct place
            heapify(mainIndex);
        }
    }

public:
    // by default the heap will be a max heap
    heap(bool type = true) {
        whichHeap = type;    // if we get true in our parameters means we wanna make a max heap
        // also we need to make sure that the first index of our array is blocked
        v.push_back(-1);
    }

    // push operation
    void push(int d) {
        // insert at last
        v.push_back(d);
        // take the element to the correct position to restore the heap
        int index = v.size() - 1;
        int parent = index / 2;
        // now check based on the kind of heap through a loop if we need to push the curr element to the top
        while (index > 1 && compare(v[index], v[parent])) {
            // swap the parent and the index thus taking up the curr element
            swap(v[index], v[parent]);
            index = parent;
            parent = index / 2;
        }
    }

    // returns the top most element which will be min in case of min heap and max in case of max heap
    T top() {
        return v[1];
    }

    // check if the heap is empty or not
    bool ifEmpty() {
        return v.size() == 1;
    }

    // delete/pop operation, heap only allows us to delete the top most element i.e smallest in min heap and largest in max heap
    void pop() {
        // firstly swap the last and the root element, then delete the last element (which was the top most element that was to be deleted)
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        // now make sure heap is correct by bringing the new topmost element to its correct place
        heapify(1); // call the heapify function to do this operation with the parameter the root element index i.e 1 (remember 0th index has -1 stored)
        return;
    }
};

int main() {
    // min heap
    heap<int> h(false);
    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(1);

    while (!h.ifEmpty()) {
        cout << h.top() << endl;
        h.pop();
    }

    return 0;
}