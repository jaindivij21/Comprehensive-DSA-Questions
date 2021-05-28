// Winning CB Scholarship Problem
// https://www.youtube.com/watch?v=YM7S1eaoCFQ

#include<iostream>
#include<climits>

using namespace std;

int main() {
    int students;
    cin >> students;

    int availableDiscountCoupons;
    cin >> availableDiscountCoupons;

    int couponsReqd;
    cin >> couponsReqd;

    int takableCoupons;
    cin >> takableCoupons;

    int l = 0;
    int r = students;
    int ans = INT_MIN;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        // check if available coupons are more than or eql to reqd coupons for mid number of students
        // if mid number of students are possible to be given scholarship, then try for more, otherwise for less
        if(mid*couponsReqd <= availableDiscountCoupons + (students-mid)*takableCoupons)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid-1;
    }
    cout<<"The max number of students that can be given the scholarship is:"<<ans<<endl;
    return 0;
}