// Sorting

#include <vector>

using namespace std;

class BubbleSort
{
public:
  static vector<int> sort(vector<int> &nums)
  {
    // Implement Bubble Sort
  }
};

class MergeSort
{
public:
  static vector<int> sort(vector<int> &nums)
  {
    // Implement Merge Sort
  }
};

class InsertionSort
{
public:
  static vector<int> sort(vector<int> &nums)
  {
    // Implement Insertion Sort
  }
};

class HeapSort
{
public:
  static vector<int> sort(vector<int> &nums)
  {
    // Implement Heap Sort
  }
};

class CountSort
{
public:
  static vector<int> sort(vector<int> &nums)
  {
    // Implement Count Sort
  }
};

class BucketSort
{
public:
  static vector<int> sort(vector<int> &nums)
  {
    // Implement Bucket Sort
  }
};

class RadixSort
{
public:
  static vector<int> sort(vector<int> &nums)
  {
    // Implement Radix Sort
  }
};

class QuickSort
{
public:
  static vector<int> sort(vector<int> &nums)
  {
    // Implement Quick Sort
  }
};

class Solution
{
public:
  static vector<int> sortArray(vector<int> &nums)
  {
    return BubbleSort::sort(nums);
  }
};

int main()
{
  vector<int> nums = {5, 2, 3, 1};

  Solution s;
  vector<int> ans = Solution::sortArray(nums);

  return 0;
}
