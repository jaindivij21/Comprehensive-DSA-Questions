// Leetcode: Smallest Number in Infinite Set
// https://leetcode.com/problems/smallest-number-in-infinite-set

#include <iostream>
#include <set>
using namespace std;

class SmallestInfiniteSet
{
   public:
    set<int> s;

    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            s.insert(i);
        }
    }

    int popSmallest()
    {
        int smallest = *s.begin();
        s.erase(s.begin());

        return smallest;
    }

    void addBack(int num) { s.insert(num); }
};

int main()
{
    SmallestInfiniteSet *obj = new SmallestInfiniteSet();
    cout << obj->popSmallest() << endl;
    obj->addBack(2);

    return 0;
}
