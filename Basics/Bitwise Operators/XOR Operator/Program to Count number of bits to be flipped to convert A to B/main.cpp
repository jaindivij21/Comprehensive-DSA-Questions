// Program to Count number of bits to be flipped to convert A to B

#include <iostream> 
using namespace std; 
  
int calculateFlips(int n)
{
    int res = 0;
    while(n)
    {
        // we use & bit wise operator with 1 to calculate if the right most bit is 1
        int temp = n&1;
        if (temp == 1)
            res++;
        n >>= 1;
    }
    return res;
}

int main()
{
    int a, b;
    cout<<"Enter the numbers"<<endl;
    cin>>a>>b;

    int exclusiveOR = a^b;  // exclusiveOR contains a binary number with only those bits set as 1 which are flipped

    int result = calculateFlips(exclusiveOR);

    cout<<"The number of bits flipped are "<<result<<endl;

    return 0;
}