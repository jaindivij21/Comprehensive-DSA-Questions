// Program to print all the prime factors of all numbers

#include<iostream>

using namespace std;

void primeFactors(int num) {
    // for all numbers from 2 to sqrt(num) ((We use sqrt(num) instead of just num to optimize the code))
    for (int i = 2; i * i < num; i++) {
        // now run a loop for each i until it divides the num, update the value of num also everytime
        while (num % i == 0) {
            cout << i << " ";
            num = num / i;
        }
    }
    // now arrange for the corner case when the most recent num value is also a factor
    if(num != 1)
        cout<<num<<endl;
    else
        cout<<endl;
}

// main
int main() {
    cout << "Enter the number" << endl;
    int num;
    cin >> num;

    primeFactors(num);

    return 0;
}