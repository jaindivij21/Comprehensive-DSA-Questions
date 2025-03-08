// Leetcode: Maximum Twin Sum of a Linked List
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

#include <iostream>
#include <stack>
using namespace std;

class ListNode
{
   public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
   public:
    int pairSum(ListNode *head)
    {
        stack<int> valuesStack;
        ListNode *slowPointer = head, *fastPointer = head;

        // Use the fast and slow pointer approach to find the middle of the list
        while (fastPointer != nullptr && fastPointer->next != nullptr)
        {
            valuesStack.push(
                slowPointer
                    ->val);  // Store the first half of values in the stack
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        int maxTwinSum = INT_MIN;

        // Compare elements from the stack with the second half of the list
        while (slowPointer != nullptr)
        {
            int topValue = valuesStack.top();
            valuesStack.pop();
            maxTwinSum = max(maxTwinSum, topValue + slowPointer->val);
            slowPointer = slowPointer->next;
        }

        return maxTwinSum;
    }
};

int main()
{
    Solution solution;
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(3);

    int result = solution.pairSum(head);

    cout << "Maximum Twin Sum: " << result << endl;

    return 0;
}
