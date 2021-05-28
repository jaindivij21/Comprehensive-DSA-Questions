// Money Change Problem
// We'll use algortihm stl class to solve this problem
// Use lower_bound function along with a comparator function

#include<iostream>
#include<algorithm>

using namespace std;

// this function returns true if the element is less than or eql to the element to be found
// in the lower bound function, thus the function moving forward
// it returns false as soon as we encounter a number *only* greater than element to be found
// and that address is returned

// by default its a<b in lower bound function i.e. it returns true for elemets less than toBeFound
// but when = or greter element is found than toBeFound, comparator func returns false
// and lower_bound retunrs address of that location
bool compare(int a, int b) {
    return a <= b;
}

int main()
{
    // this lower_bound function used works since this is a sorted array
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};    //120
    int n = sizeof(coins)/sizeof(int);
    int money;
    cin>>money;

    // run a loop until money is not eql to 0
    while(money > 0)
    {
        // a custom lower_bound function that returns the address of
        int lb = lower_bound(coins, coins+n, money, compare) - coins - 1;
        int temp = coins[lb];
        cout<<temp<<",";
        money = money - temp;
    }
        return 0;
}