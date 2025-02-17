#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
  vector<int> heap;

  // Determines heap order based on type (min or max)
  bool compare(int a, int b) const
  {
    return heapType == HeapType::MIN ? a < b : a > b;
  }

  // Moves the last inserted element to its correct position
  void heapifyUp()
  {
    int index = heap.size() - 1;
    while (index > 0)
    {
      int parent = (index - 1) / 2;
      if (!compare(heap[index], heap[parent]))
        break;
      swap(heap[index], heap[parent]);
      index = parent;
    }
  }

  // Moves the root element down to maintain heap property
  void heapifyDown(int index)
  {
    int size = heap.size();
    while (true)
    {
      int leftChild = 2 * index + 1;
      int rightChild = 2 * index + 2;
      int smallestOrLargest = index;

      if (leftChild < size && compare(heap[leftChild], heap[smallestOrLargest]))
      {
        smallestOrLargest = leftChild;
      }
      if (rightChild < size && compare(heap[rightChild], heap[smallestOrLargest]))
      {
        smallestOrLargest = rightChild;
      }
      if (smallestOrLargest == index)
        break;

      swap(heap[index], heap[smallestOrLargest]);
      index = smallestOrLargest;
    }
  }

public:
  enum class HeapType
  {
    MIN,
    MAX
  };
  HeapType heapType;

  explicit Heap(HeapType type = HeapType::MIN) : heapType(type) {}

  // Inserts a new value into the heap
  void push(int value)
  {
    heap.push_back(value);
    heapifyUp();
  }

  // Removes and returns the root element
  int pop()
  {
    if (heap.empty())
    {
      throw runtime_error("Heap is empty");
    }
    int topElement = heap.front();
    heap.front() = heap.back();
    heap.pop_back();
    if (!heap.empty())
      heapifyDown(0);
    return topElement;
  }

  // Prints the heap elements
  void print() const
  {
    for (int num : heap)
    {
      cout << num << " ";
    }
    cout << endl;
  }
};

int main()
{
  Heap maxHeap(Heap::HeapType::MAX);
  maxHeap.push(10);
  maxHeap.push(20);
  maxHeap.push(15);
  maxHeap.push(30);
  maxHeap.push(40);
  maxHeap.push(5);

  cout << "Heap elements after push: ";
  maxHeap.print();

  while (true)
  {
    try
    {
      cout << "Extracted: " << maxHeap.pop() << endl;
    }
    catch (const runtime_error &e)
    {
      cout << "Heap is empty" << endl;
      break;
    }
  }

  return 0;
}
