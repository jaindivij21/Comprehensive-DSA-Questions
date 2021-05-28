// Ladders Problem using recusion
// No of ways to reach the nth stair if he can jump either 1,2 or 3 stairs at a time
// https://www.geeksforgeeks.org/count-ways-reach-nth-stair/

#include<iostream>

using namespace std;

int waysToClimb(int n) {
    // base cases
//    reached the top
//    if (n == 0)
//        return 0;
//    if (n == 3)
//        return 3;
//    if (n == 2)
//        return 2;
//    if (n == 1)
//        return 1;
// all the above cases can also be written as:
    if (n <= 3)
        return n;

    // recursive cases
    int x = waysToClimb(n - 3);
    int y = waysToClimb(n - 2);
    int z = waysToClimb(n - 1);

    return x + y + z;
}


int main() {
    // input total stairs
    int n;

    // input
    cout << "Enter the total stairs" << endl;
    cin >> n;


    //  main
    cout << "Ways in which person can climb stairs: " << waysToClimb(n) << endl;
    return 0;
}