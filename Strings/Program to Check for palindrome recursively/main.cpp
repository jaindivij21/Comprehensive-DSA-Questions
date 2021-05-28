#include <iostream>
#include<cstring>

using namespace std;

bool palindrome(char a[100], int n, int left, int right) {
    if (n == 1) {
        return true;
    }
    if(left >= right){
       return palindrome(a,n,left+1,right-1); // look closely, to understand '=' think of odd number of elements and also changed the sign
    }
    if (a[left] != a[right]) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n; //input n
    char a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = palindrome(a, n, 0, n - 1);
    cout<<(x==0?"false":"true");
    return 0;
}
