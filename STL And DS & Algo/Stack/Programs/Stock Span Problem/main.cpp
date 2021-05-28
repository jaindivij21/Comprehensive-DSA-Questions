// STOCK SPAN PROBLEM
// https://www.geeksforgeeks.org/the-stock-span-problem/
// https://www.youtube.com/watch?v=-IFmgue8sF0
/*
 * Stock span for a day is the number of days it has been the highest stock price. That is
 * subtract today's day with the day that was higher than today's price.
 *
 * Brute Force solution will be O(n2) as we iterate back from each day everytime to find the day
 * with a higher price than today and then cal the span. Stacks can be a better option!
 */

// Will solve using stacks o(n)
 
#include <iostream>
#include<stack>

using namespace std;

// main function
/*
 *  if the today's price is less than prev days price, then simply the span is 1
 *  if the price is higher than yesterday's price, we keep on popping the previous prices until we reach a higher
 *  price, and thus cal the span.
 *  TAKE CARE about the corner case
 */

void stockSpan(int span[], int price[], int days) {
    stack<int> s;
    s.push(0);
    // make the span for day 1 as 1 (mandatory)
    span[0] = 1;

    // loop for the rest of the days
    for (int i = 1; i < days; i++) {
        int currPrice = price[i];
        // find the topmost stack element higher than today's/curr price
        while (!s.empty() and price[s.top()] <= currPrice) {
            // pop if the price is less
            s.pop();
        }
        // if the price is higher than curr
        if (!s.empty()) {
            int prevHighestDay = s.top();
            span[i] = i - prevHighestDay;
        } else {
            // CORNER CASE
            // means the highest stock price has been encountered now
            // therefore span = number of days
            span[i] = i + 1;
        }
        // push the element into the stack
        s.push(i);
    }
}

int main() {
    // input the info
    int days;
    cout << "Enter the number of days" << endl;
    cin >> days;
    cout << "Enter the prices" << endl;
    int arr[days];
    for (int i = 0; i < days; i++) {
        cin >> arr[i];
    }

    // make an array to store the spans
    int span[days] = {0};

    // main function
    stockSpan(span, arr, days);

    // print out the spans
    for (int i = 0; i < days; i++) {
        cout << "Day " << i << ": " << span[i] << endl;
    }

    return 0;
}
