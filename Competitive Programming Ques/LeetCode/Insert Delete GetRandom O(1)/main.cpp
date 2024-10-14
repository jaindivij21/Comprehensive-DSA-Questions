// Leetcode: Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1

#include <iostream>
#include <unordered_map>

using namespace std;

class RandomizedSet
{
public:
  unordered_map<int, int> nums;

  RandomizedSet() = default;

  bool insert(int val)
  {
    if (nums.find(val) == nums.end())
    {
      nums[val] = val;
      return true;
    }
    else
    {
      return false;
    }
  }

  bool remove(int val)
  {
    if (nums.find(val) == nums.end())
    {
      return false;
    }
    else
    {
      nums.erase(val);
      return true;
    }
  }

  int getRandom()
  {
    int random = rand() % nums.size();
    auto itr = nums.begin();
    advance(itr, random);
    return itr->first;
  }
};

int main()
{
  auto *obj = new RandomizedSet();
  cout << obj->insert(1) << endl;
  cout << obj->remove(2) << endl;
  cout << obj->insert(2) << endl;
  cout << obj->getRandom() << endl;
  cout << obj->remove(1) << endl;
  cout << obj->insert(2) << endl;
  cout << obj->getRandom() << endl;

  delete obj;

  return 0;
}